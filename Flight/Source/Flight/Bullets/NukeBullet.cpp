// Fill out your copyright notice in the Description page of Project Settings.

#include "Flight.h"
#include "NukeBullet.h"
#include "enemyController.h"
ANukeBullet::ANukeBullet()
{
	MovementComponent->InitialSpeed = 0;
	ScaleOverTime = 0;
	OnActorBeginOverlap.AddDynamic(this, &ANukeBullet::OnBeginOverlap);
}
void ANukeBullet::OnBeginOverlap(AActor* OtherActor)
{
	AenemyController* Enemy = Cast<AenemyController>(OtherActor);
	if (Enemy)
	{
		UGameplayStatics::ApplyDamage(Enemy, Damage * DamageScale,NULL, GetOwner(), UDamageType::StaticClass());
	}
}
void ANukeBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorRelativeScale3D(FVector(timeAlive * ScaleOverTime, timeAlive * ScaleOverTime, timeAlive * ScaleOverTime));

}
