// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS(abstract)
class GALAGA_USFX_L_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()

public:

	// ~~ Componente raiz que controlara los demas componentes ~~ 
	UPROPERTY(EditAnywhere)
	USceneComponent* Scena;

	// ~~ Conponente de Malla para la nave ~~
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Componentes")
	class UStaticMeshComponent* Nave_Mesh;

	// ~~ Componente de Explosion ~~
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Componentes")
	class UParticleSystem* Explosion_Nave;

	// ~~ Componente de Colsion : tipo caja ~~
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Componentes")
	class UBoxComponent* Colision_Nave;

	// ~~ Componente de Sonido ~~
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Componentes")
	class USoundBase* Sonido_Nave;

	UPROPERTY(EditAnywhere, Category = "Componentes")
	class UCapsuleComponent* ShipEnemyCollision; // para colisiones
	
public:	
	// Sets default values for this actor's properties
	ANaveEnemiga();
	// nombre de la nave
	FString Nombre_Nave;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Metodo para hacer daño a esta nave
	virtual void WeaponDamage(float Damage) {};

	// Vida de la nave
	float Life;

	virtual void ComponenteDeDestruccion();

	virtual void Damage(float Damage);

	float Velocidad;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
