// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyLevel2.h"
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

void AEnemyLevel2::BeginPlay()
{
	Super::BeginPlay();
}

AEnemyLevel2::AEnemyLevel2()
{
	// Conguracion de este actor en cada fotograma del juego 
	PrimaryActorTick.bCanEverTick = true;

	//|| COMPONENTE MALLA DE LA NAVE ||
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel2.EnemyLevel2'"));
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

	SetActorRelativeScale3D(FVector(2.5f, 2.5f, 2.5f));
	//|| PARA AJUSTAR LOS LIMITES DE COLISION DE LA NAVE ||
	Colision_Nave->SetBoxExtent(FVector(50.f, 50.f, 50.f));

	// configurando el campo de colision de este actor
	ShipEnemyCollision->SetCapsuleHalfHeight(28.0f);
	ShipEnemyCollision->SetCapsuleRadius(28.0f);

	// configurando la vida de la nave
	Life = 50.0f;

	// asignandole el nombre
	Nombre_Nave = "EnemyLevel2";
	// inicializando variables para el uso del nivel 2
	Tiempo_Disparo = 0;// tiempo de disparo
	Tiempo_Disparo_Generar = 0;// tiempo de disparo
	Distancia_Disparo = FVector(20.f, 0.f, 0.f);// distancia de disparo
}

void AEnemyLevel2::Tick(float DeltaTime)
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
	
	// Contador de tiempo para el disparo
	Tiempo_Disparo += DeltaTime;
	if (Tiempo_Disparo >= Tiempo_Disparo_Generar) {
		Tiempo_Disparo = 0.f;

		// Declaración de la dirección y rotación del primer proyectil
		const FVector Direccion_Disparo = FVector(-1.f, 0.f, 0.f);
		const FRotator Rotacion_Disparo = Direccion_Disparo.Rotation();
		const FVector Ubicacion_Disparo = GetActorLocation() + Rotacion_Disparo.RotateVector(Distancia_Disparo);

		// Desplazamientos adicionales para los proyectiles restantes
		const float DesplazamientoEntreProyectiles = 50.f; // Ajusta según sea necesario
		const FVector DesplazamientoAdicional = FVector(0.f, DesplazamientoEntreProyectiles, 0.f);

		// Verificación de si el mundo no está vacío
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// Spawn de los tres proyectiles
			World->SpawnActor<AGALAGA_USFX_LProjectile>(Ubicacion_Disparo, Rotacion_Disparo);
		}
	}
}

void AEnemyLevel2::Damage(float Damage)
{
	Life -= Damage;
}

void AEnemyLevel2::NotifyActorBeginOverlap(AActor* OtherActor)
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
	// que el proyectil solo dañe a la nave enemiga

}

void AEnemyLevel2::ComponenteDeDestruccion()
{
	if (Explosion_Nave)
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion_Nave, GetActorTransform());
	// sonido de la explosion
	if (Sonido_Nave != nullptr && this->GetActorLocation().X > -850.f)
		UGameplayStatics::PlaySoundAtLocation(this, Sonido_Nave, GetActorLocation());
	// si te chocas con este actor te quita 10 puntos
	this->Destroy();
}
