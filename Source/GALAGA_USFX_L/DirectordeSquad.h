// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SquadBuilder.h"
#include "DirectordeSquad.generated.h"

class ISquadBuilder;

UCLASS()
class GALAGA_USFX_L_API ADirectordeSquad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectordeSquad();

private:
	ISquadBuilder* SquadBuilder;

public:

	// Crea los escuadrones
	void ConstructSquads(FString _SquadLevel);

	// Establecer el actor constructor
	void setSquadBuilder(AActor* Builder);

};
