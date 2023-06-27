// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangePoint.h"

#include "Components/BoxComponent.h"

#include "BaseChar.h"


// Sets default values
AChangePoint::AChangePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Box->SetRelativeScale3D(FVector(3));
	
}

// Called when the game starts or when spawned
void AChangePoint::BeginPlay()
{
	Super::BeginPlay();
	
	Box->OnComponentBeginOverlap.AddDynamic(this, &AChangePoint::OnOverlapBegin);

}

// Called every frame
void AChangePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangePoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Character = Cast<ABaseChar>(OtherActor);

	if (Character)
	{
		Character->ChangeChar();
	}
	
}

