// Copyright Epic Games, Inc. All Rights Reserve

#include "GALAGA_USFX_LProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"
#include "NaveEnemigaEspia.h"
#include "EnemyLevel1.h"
#include "EnemyLevel2.h"
#include "EnemyLevel3.h"
#include "EnemyLevel4.h"
#include "EnemyLevel5.h"


AGALAGA_USFX_LProjectile::AGALAGA_USFX_LProjectile() 
{
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/BulletEnemyLevel1.BulletEnemyLevel1'"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AGALAGA_USFX_LProjectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AGALAGA_USFX_LProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}
	ANaveEnemigaEspia* NaveEspia = Cast<ANaveEnemigaEspia>(OtherActor);
	if (NaveEspia != nullptr)
	{
		NaveEspia->Damage( 20.0f);
	}
	AEnemyLevel1* EnemyLevel1 = Cast<AEnemyLevel1>(OtherActor);
	if (EnemyLevel1 != nullptr)
	{
		EnemyLevel1->Damage(20.0f);
	}
	AEnemyLevel2* EnemyLevel2 = Cast<AEnemyLevel2>(OtherActor);
	if (EnemyLevel2 != nullptr)
	{
		EnemyLevel2->Damage(20.0f);
	}
	AEnemyLevel3* EnemyLevel3 = Cast<AEnemyLevel3>(OtherActor);
	if (EnemyLevel3 != nullptr)
	{
		EnemyLevel3->Damage(20.0f);
	}
	AEnemyLevel4* EnemyLevel4 = Cast<AEnemyLevel4>(OtherActor);
	if (EnemyLevel4 != nullptr)
	{
		EnemyLevel4->Damage(20.0f);
	}
	AEnemyLevel5* EnemyLevel5 = Cast<AEnemyLevel5>(OtherActor);
	if (EnemyLevel5 != nullptr)
	{
		EnemyLevel5->Damage(20.0f);
	}

	Destroy();
}