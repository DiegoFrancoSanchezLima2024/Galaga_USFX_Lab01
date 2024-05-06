// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyLevel4.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/ShapeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GALAGA_USFX_LProjectile.h"
#include "GALAGA_USFX_LPawn.h"
#include "Sound/SoundBase.h"
#include "Components/BoxComponent.h"

void AEnemyLevel4::BeginPlay()
{
	Super::BeginPlay();
}

AEnemyLevel4::AEnemyLevel4()
{
	// Conguracion de este actor en cada fotograma del juego 
	PrimaryActorTick.bCanEverTick = true;

	//|| COMPONENTE MALLA DE LA NAVE ||
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel4.EnemyLevel4'"));
	if (MeshAsset.Succeeded())
	{
		Nave_Mesh->SetStaticMesh(MeshAsset.Object);

		// Modificar la escala del componente de malla
		FVector NewScale(0.500f, 0.500f, 0.500f); // Escala modificada
		Nave_Mesh->SetWorldScale3D(NewScale);
	}
	//|| COMPONENTE DE PARTICULA DE LA NAVE ||
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

	if (ParticleAsset.Succeeded())
	{
		Explosion_Nave = Cast<UParticleSystem>(ParticleAsset.Object);
	}

	//|| COMPONENTE DE SONIDO DE LA NAVE ||
	static ConstructorHelpers::FObjectFinder<USoundBase> AssetExplosionSound(TEXT("SoundWave'/Game/StarterContent/Audio/Explosion02.Explosion02'"));
	if (AssetExplosionSound.Succeeded())
	{
		Sonido_Nave = Cast<USoundBase>(AssetExplosionSound.Object);
	}
	SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));

	SetActorRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));
	//|| PARA AJUSTAR LOS LIMITES DE COLISION DE LA NAVE ||
	Colision_Nave->SetBoxExtent(FVector(50.f, 50.f, 50.f));

	// configurando el campo de colision de este actor
	ShipEnemyCollision->SetCapsuleHalfHeight(28.0f);
	ShipEnemyCollision->SetCapsuleRadius(28.0f);

	// configurando la vida de la nave
	Life = 50.0f;

	// asignandole el nombre
	Nombre_Nave = "EnemyLevel4";
}

void AEnemyLevel4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Haciendo mover la nave enemiga
	const FVector MoveDirection = FVector(-1.f, 0.f, 0.f);		// direccion del movimiento
	const FVector Movement = MoveDirection * Velocidad * DeltaTime;	// la velocidad en la que se va mover

	if (Movement.SizeSquared() > 0.0f) {
		const FRotator NewRotation = FRotator(180.0f, 0.0f, 180.0f); // la rotacion de la nave enemiga

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
	// destruir la nave enemiga si sobrepasa el punto 850 en el eje de las X o si ya no tiene vida
	if (this->GetActorLocation().X < -1650.f || Life <= 0)
	{
		ComponenteDeDestruccion();
	}

	// destruir la nave si ya no tiene vida
	if (Life <= 0)
	{
		ComponenteDeDestruccion();
	}
}

void AEnemyLevel4::Damage(float Damage)
{
	Life -= Damage;
}

void AEnemyLevel4::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	UE_LOG(LogTemp, Warning, TEXT("collect with %s"), *OtherActor->GetFName().ToString());

	// verificamos que se la nave jugador
	AGALAGA_USFX_LProjectile* Player = Cast<AGALAGA_USFX_LProjectile>(OtherActor);
	if (Player)
	{
		//Player->Damage(20.f);
		ComponenteDeDestruccion();
	}


	AGALAGA_USFX_LPawn* Nave = Cast<AGALAGA_USFX_LPawn>(OtherActor);
	if (Nave)
	{
		ComponenteDeDestruccion();
	}
}

void AEnemyLevel4::ComponenteDeDestruccion()
{
	if (Explosion_Nave)
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion_Nave, GetActorTransform());
	// sonido de la explosion
	if (Sonido_Nave != nullptr && this->GetActorLocation().X > -850.f)
		UGameplayStatics::PlaySoundAtLocation(this, Sonido_Nave, GetActorLocation());
	// si te chocas con este actor te quita 10 puntos
	this->Destroy();
}
