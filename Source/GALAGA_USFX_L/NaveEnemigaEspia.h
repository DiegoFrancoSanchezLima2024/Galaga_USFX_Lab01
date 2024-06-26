// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"


UCLASS()
class GALAGA_USFX_L_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ANaveEnemigaEspia();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// metodo para hacer da�o a esta nave
	virtual void Damage(float Damage) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void ComponenteDeDestruccion() override;

};
