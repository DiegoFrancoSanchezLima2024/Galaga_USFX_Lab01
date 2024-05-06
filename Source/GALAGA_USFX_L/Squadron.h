// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SquadMembers.h"
#include "Squadron.generated.h"

UCLASS()
class GALAGA_USFX_L_API ASquadron : public AActor, public ISquadMembers
{
	GENERATED_BODY()
	
public:
	// Constructor
	ASquadron();

public:
	UPROPERTY(VisibleAnywhere, Category = "Squadron")
	UStaticMeshComponent* MeshSquad;

public:
	// Metodos para construir los escuadrones
	void setSquadronLevel1() override;
	void setSquadronLevel2() override;
	void setSquadronLevel3() override;
	void setSquadronLevel4() override;
	void setSquadronLevel5() override;
	void SetMesh(UStaticMeshComponent* MiMeshSquad);
};
