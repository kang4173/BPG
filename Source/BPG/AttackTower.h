// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BPG/BaseChar.h"
#include "Containers/Queue.h"
#include "Particles/ParticleSystemComponent.h"
#include "AttackTower.generated.h"

UCLASS()
class BPG_API AAttackTower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttackTower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshCom;


	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UBoxComponent* Box;

	UFUNCTION()
	void Attack();


	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex);


	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	TArray <ABaseChar*> AttackArr;


	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UParticleSystemComponent* SettingEmitter;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UParticleSystem* Particle;


	bool Cooldown=true;


	float AttackTimeAcc;

	float AttackInterval = 1;

	ABaseChar* Owner;


};
