// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BPG/BaseChar.h"
#include "Particles/ParticleSystemComponent.h"
#include "Missile.generated.h"

UCLASS()
class BPG_API AMissile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMissile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex);

	ABaseChar* Owner;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UParticleSystem* Particle;

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UParticleSystemComponent* SettingEmitter;


	void CollisionSet();

	FTimerHandle  TimerHandle;
	


};
