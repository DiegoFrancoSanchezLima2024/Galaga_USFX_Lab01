// Fill out your copyright notice in the Description page of Project Settings.


#include "Squadron.h"
#include "EnemyLevel1.h"
#include "EnemyLevel2.h"
#include "EnemyLevel3.h"
#include "EnemyLevel4.h"
#include "EnemyLevel5.h"

// Sets default values
ASquadron::ASquadron()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshSquad = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshSquad"));
	MeshSquad->SetupAttachment(RootComponent);
	RootComponent = MeshSquad;

}
// establecer el nivel de escuadron
void ASquadron::setSquadronLevel1()
{
	const FRotator Rotation = FRotator(0.f, 0.f, 0.f);
	const float StartX = 650.f;
	const float StartY = 240.f;
	const float GapY = 150.f; // espacio entre nave 
	const int32 Rows = 3;
	const int32 Cols = 8;

	for (int32 Row = 0; Row < Rows; ++Row)
	{
		for (int32 Col = 0; Col < Cols; ++Col)
		{
			const float LocationY = StartY - (GapY * Col);
			const FVector Location = FVector(StartX, LocationY, 210.f);
			GetWorld()->SpawnActor<AEnemyLevel1>(Location, Rotation);
		}
	}
}

// Estableciendo el escuadron de nivel 2
void ASquadron::setSquadronLevel2()
{
	const FRotator Rotation = FRotator(0.f, 0.f, 0.f);
	const float StartX = 620.f;
	const float StartY = 280.f;
	const float GapX = 130.f;
	const float GapY = 190.f;
	const int32 Rows = 5;
	const int32 Cols = 4;

	for (int32 Row = 0; Row < Rows; ++Row)
	{
		for (int32 Col = 0; Col < Cols; ++Col)
		{
			const float LocationX = StartX + (GapX * Col);
			const float LocationY = StartY - (GapY * Row);
			const FVector Location = FVector(LocationX, LocationY, 210.f);
			GetWorld()->SpawnActor<AEnemyLevel2>(Location, Rotation);
		}
	}
}

// Estableciendo el escuadron de nivel 3
void ASquadron::setSquadronLevel3()
{
	const FRotator Rotation = FRotator(0.f, 0.f, 0.f);
	const float StartX = 650.f;
	const float StartY = 375.f;
	const float GapX = 150.f;
	const float GapY = 190.f;
	const int32 Rows = 4;
	const int32 Cols = 3;

	for (int32 Row = 0; Row < Rows; ++Row)
	{
		for (int32 Col = 0; Col < Cols; ++Col)
		{
			const float LocationX = StartX + (GapX * Col);
			const float LocationY = StartY - (GapY * Row);
			const FVector Location = FVector(LocationX, LocationY, 210.f);
			GetWorld()->SpawnActor<AEnemyLevel3>(Location, Rotation); 
		}
	}
}

// Estableciendo el escuadron de nivel 4
void ASquadron::setSquadronLevel4()
{
	const FRotator Rotation = FRotator(0.f, 0.f, 0.f);
	const float StartX = 650.f;
	const float StartY = 250.f;
	const float GapX = 200.f;
	const float GapY = 190.f;
	const int32 Rows = 4;
	const int32 Cols = 5;

	for (int32 Row = 0; Row < Rows; ++Row)
	{
		for (int32 Col = 0; Col < Cols; ++Col)
		{
			const float LocationX = StartX + (GapX * Col);
			const float LocationY = StartY - (GapY * Row);
			const FVector Location = FVector(LocationX, LocationY, 230.f);
			GetWorld()->SpawnActor<AEnemyLevel4>(Location, Rotation);
		}
	}
}

// Estableciendo el escuadron de nivel 5
void ASquadron::setSquadronLevel5()
{
	const FRotator Rotation = FRotator(0.f, 0.f, 0.f);
	const float StartX = 650.f;
	const float StartY = 360.f;
	const float GapX = 150.f;
	const float GapY = 190.f;

	for (int32 Row = 0; Row < 6; ++Row)
	{
		for (int32 Col = 0; Col < 5; ++Col)
		{
			const float LocationX = StartX + (GapX * Col);
			const float LocationY = StartY - (GapY * Row);
			const FVector Location = FVector(LocationX, LocationY, 230.0f);
			GetWorld()->SpawnActor<AEnemyLevel5>(Location, Rotation);
		}
	}
}

void ASquadron::SetMesh(UStaticMeshComponent* MiMeshSquad)
{
	MeshSquad = MiMeshSquad;
}

