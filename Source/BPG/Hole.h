// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BPG/BaseChar.h"
#include "Components/TimelineComponent.h"
#include "Hole.generated.h"

UCLASS()
class BPG_API AHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UStaticMeshComponent* Mesh;


	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	USphereComponent* Sphere;


	

	ABaseChar* Owner;

	TArray<ABaseChar*> ABaseCharArray;

	bool IsOn=true;

	bool IsActive=false;

	float Five=0;



	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex);


	UFUNCTION(BlueprintCallable)
	void Active();

	FTimeline MyTimeline;

	UFUNCTION(BlueprintCallable)
	void AddOverlappingActors();


	UFUNCTION(BlueprintCallable)
	void CheckArray();




};
