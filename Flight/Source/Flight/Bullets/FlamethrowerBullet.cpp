// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "FlamethrowerBullet.h"
#include "enemyController.h"
#include "RealBoss.h"

AFlamethrowerBullet::AFlamethrowerBullet()
{
	OnActorBeginOverlap.AddDynamic(this, &AFlamethrowerBullet::OnBeginOverlap);
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System"));
	ParticleSystem->AttachTo(RootComponent);
}

void AFlamethrowerBullet::OnBeginOverlap(AActor* OtherActor)
{
	AenemyController* Enemy = Cast<AenemyController>(OtherActor);

	if (Enemy)
	{
		//Enemy->TakeDamge(Damage);
		UGameplayStatics::ApplyDamage(Enemy, Damage * DamageScale,
			NULL, GetOwner(), UDamageType::StaticClass());
		Destroy();
		return;
	}
	ARealBoss* Boss = Cast<ARealBoss>(OtherActor);
	if (Boss)
	{
		UGameplayStatics::ApplyDamage(Boss, Damage * DamageScale, NULL, GetOwner(), UDamageType::StaticClass());
		Destroy();
		return;
	}
}

