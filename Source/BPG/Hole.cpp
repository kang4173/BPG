// Fill out your copyright notice in the Description page of Project Settings.


#include "Hole.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AHole::AHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	Sphere = CreateDefaultSubobject< USphereComponent>(TEXT("Sphere"));
	//Mesh->SetupAttachment(RootComponent);
	RootComponent= Mesh;
	Sphere->SetupAttachment(Mesh);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_StaticMeshComponent(TEXT("StaticMesh'/Engine/VREditor/TransformGizmo/RotationHandleFull.RotationHandleFull'"));
	if (SM_StaticMeshComponent.Succeeded())
	{
		Mesh->SetStaticMesh(SM_StaticMeshComponent.Object);
		//Mesh->SetRelativeLocationAndRotation(FVector(0,0,0),FRotator(90,0,0));
		Mesh->SetWorldRotation(FRotator(90 , 0 , 0));
		Sphere->SetRelativeLocationAndRotation(FVector::ZeroVector,FRotator(0 , 0 , 0) );
		Sphere->SetWorldScale3D(FVector(10,10,10));
		Sphere->SetHiddenInGame(false);

		Sphere->OnComponentBeginOverlap.AddDynamic(this , &AHole::OnOverlapBegin);
		Sphere->OnComponentEndOverlap.AddDynamic(this , &AHole::OnOverlapEnd);
	}
	MyTimeline=FTimeline();



}

// Called when the game starts or when spawned
void AHole::BeginPlay()
{
	Super::BeginPlay();

	//ABaseCharArray[10];
	
}

// Called every frame
void AHole::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	Five+=DeltaTime;
	if (Five >= 5)
	{
		Destroy(true);
	}
	if (IsOn)
	{
		GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Red , FString::Printf(TEXT("IsOn")));
		AddOverlappingActors();
		IsOn=false;
		
	}
	if (IsActive)
	{
		Active();
	}
}

void AHole::OnOverlapBegin(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult)
{
	ABaseCharArray.AddUnique(Cast<ABaseChar>(OtherActor));
}

void AHole::OnOverlapEnd(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex)
{
	ABaseCharArray.Remove(Cast<ABaseChar>(OtherActor));
}

void AHole::Active()
{
	GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Magenta , FString::Printf(TEXT("HoleManActive")));

	
	
	
	for (int i = 0; i < ABaseCharArray.Num() - 1; i++)
	{
		//FVector NewLocation = Sphere->GetComponentLocation();
		FVector TargetLocation= Sphere->GetComponentLocation();
		FVector BaseCharLocation = ABaseCharArray[i]->GetActorLocation();
		float InterpolationSpeed = 0.1f;
		FVector NewLocation = FMath::Lerp(BaseCharLocation , TargetLocation , InterpolationSpeed);
		ABaseCharArray[i]->SetActorLocation(NewLocation);
	
		//FVector Offset = BaseChar->GetActorLocation() - NewLocation;
		//NewLocation += Offset;
		//BaseChar->SetActorLocation(NewLocation,true);
		//MyTimeline.SetPlayRate(0.1f);
		//MyTimeline.SetLooping(false);
		//MyTimeline.SetTimelineFinishedFunc(FOnTimelineEvent::(this , &AMyActor::OnTimelineFinished));
	}
}

void AHole::AddOverlappingActors()
{

	TArray<AActor*> OverlappingActors;
	GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Orange , FString::Printf(TEXT("OverlappingActor")));
	Sphere->GetOverlappingActors(OverlappingActors , AActor::StaticClass());
	GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Red, FString::Printf(TEXT("ABaseCharArray: %d") , (ABaseCharArray.Num())));
	for (AActor* OverlappingActor : OverlappingActors)
	{
		GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Green , FString::Printf(TEXT("OverlappingActor: %s") , *(OverlappingActor->GetName())));
		
		if (ABaseChar* ExBaseChar = Cast<ABaseChar>(OverlappingActor))
		{ 
			GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Silver , FString::Printf(TEXT("OverlappingActor: %s") , *(ExBaseChar->GetName())));
			ABaseCharArray.AddUnique(ExBaseChar);
			
			//GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Orange , FString::Printf(TEXT("ABaseCharArray: %f") , (ABaseCharArray.Num())));
			
		}

		
	}
	GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Magenta, FString::Printf(TEXT("ABaseCharArray: %d") , (ABaseCharArray.Num())));
	//Active();
	IsActive = true;
	
	//for (ABaseChar* ExActor : ABaseCharArray)
	//{
	//
	//	GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Silver , FString::Printf(TEXT("EsxActor: %s") , *(ExActor->GetName())));
	//}
}

void AHole::CheckArray()
{

	for (int i = 0; i < ABaseCharArray.Num() - 1; i++)
	{

		GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Red , FString::Printf(TEXT("ExBaseChar: %s") , *(ABaseCharArray[i]->GetName())));
	}
	//for (ABaseChar* ExBaseChar : ABaseCharArray)
	//{
	//	//GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Magenta , FString::Printf(TEXT("ABaseCharArray: %d") , (ABaseCharArray.Num())));
	//
	//}
}





