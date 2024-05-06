// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleSquadsReady.h"
#include "Squadron.h"
#include "EnemyLevel1.h"
#include "EnemyLevel2.h"
#include "EnemyLevel3.h"
#include "EnemyLevel4.h"
#include "EnemyLevel5.h"

// Sets default values
ABattleSquadsReady::ABattleSquadsReady()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABattleSquadsReady::BeginPlay()
{
	Super::BeginPlay();

	// Engendrar los actores de escuadrones
	Squadron = GetWorld()->SpawnActor<ASquadron>(ASquadron::StaticClass());

	// Adjuntarlo al constructor
	Squadron->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABattleSquadsReady::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABattleSquadsReady::buildSquadron1()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildSquadron1(): Squadron es NULL, asegúrese de que esté inicializado."));
		return;
	}
	// Construir escuadron de nivel 1
	Squadron->setSquadronLevel1();
}


void ABattleSquadsReady::buildSquadron2()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildSquadron2(): Squadron es NULL, asegúrese de que esté inicializado."));
		return;
	}
	//Establecer el area de la Piscina del Hospedaje
	Squadron->setSquadronLevel2();
}

void ABattleSquadsReady::buildSquadron3()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildSquadron3(): Squadron es NULL, asegúrese de que esté inicializado."));
		return;
	}
	//Establecer el area de la Piscina del Hospedaje
	Squadron->setSquadronLevel3();
}

void ABattleSquadsReady::buildSquadron4()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildSquadron4(): Squadron es NULL, asegúrese de que esté inicializado."));
		return;
	}
	//Establecer el area de la Piscina del Hospedaje
	Squadron->setSquadronLevel4();
}

void ABattleSquadsReady::buildSquadron5()
{
	if (!Squadron) {
		UE_LOG(LogTemp, Error, TEXT("buildSquadron5(): Squadron es NULL, asegúrese de que esté inicializado."));
		return;
	}
	//Establecer el area de la Piscina del Hospedaje
	Squadron->setSquadronLevel5();
}

void ABattleSquadsReady::BuildMesh()
{
	Squadron->MeshSquad->SetStaticMesh(Squadrones);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MeshSquadron"));
}

ASquadron* ABattleSquadsReady::GetSquadron()
{
	return Squadron;
}
