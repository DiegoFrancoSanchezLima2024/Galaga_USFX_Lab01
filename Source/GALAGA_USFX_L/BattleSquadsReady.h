// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SquadBuilder.h"
#include "BattleSquadsReady.generated.h"

class ASquadron;

UCLASS()
class GALAGA_USFX_L_API ABattleSquadsReady : public AActor, public ISquadBuilder
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleSquadsReady();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void buildSquadron1() override;
	virtual void buildSquadron2() override;
	virtual void buildSquadron3() override;
	virtual void buildSquadron4() override;
	virtual void buildSquadron5() override;
	virtual void BuildMesh() override;
	class UStaticMesh* Squadrones = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'")); 
	virtual class ASquadron* GetSquadron() override;
	ASquadron* Squadron;

};
