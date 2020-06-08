// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

UCLASS()
class TESTINGGROUNDS_API AInfiniteTerrainGameMode : public ATestingGroundsGameMode
{
	GENERATED_BODY()

public:
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

	UFUNCTION(BlueprintCallable, Category = "Scoring")
	int GetScore();

	UFUNCTION(BlueprintCallable, Category = "Scoring")
	void IncrementScore();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;

	UPROPERTY(EditDefaultsOnly, Category = "Scoring")
	int Score;

private:
	void AddToPool(class ANavMeshBoundsVolume* VolumeToAdd);
};
