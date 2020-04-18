// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrollingGuard.h" // TODO Remove Coupling
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    // TODO Protect against Empty Patrol Routes

    // Get the Patrol Points
    auto AIController = OwnerComp.GetAIOwner();
    auto ControlledPawn = AIController->GetPawn();
    auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
    auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

    // Set Next Waypoint
    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

    // Cycle the Index
    auto NextIndex = (Index + 1) % PatrolPoints.Num();
    BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
    
    return EBTNodeResult::Succeeded;
}
