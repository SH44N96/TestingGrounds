// Fill out your copyright notice in the Description page of Project Settings.

#include "EngineUtils.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "InfiniteTerrainGameMode.h"

void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while(VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume* VolumeToAdd)
{
	UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *VolumeToAdd->GetName());
}
