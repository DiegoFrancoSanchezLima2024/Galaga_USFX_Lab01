// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "EnemyLevel2.generated.h"


UCLASS()
class GALAGA_USFX_L_API AEnemyLevel2 : public ANaveEnemiga
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// Sets default values for this actor's properties
	AEnemyLevel2();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// metodo para hacer daño a esta nave
	virtual void Damage(float Damage) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void ComponenteDeDestruccion() override;

public:
	float Tiempo_Disparo;
	float Tiempo_Disparo_Generar;
	FVector Distancia_Disparo;

};