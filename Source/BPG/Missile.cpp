// Fill out your copyright notice in the Description page of Project Settings.


#include "Missile.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"


// Sets default values
AMissile::AMissile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MyMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	if (MyMesh.Succeeded())
	{
		Mesh->SetStaticMesh(MyMesh.Object);
		Mesh->SetCollisionProfileName(FName(TEXT("OverlapAll")));

		Mesh->OnComponentBeginOverlap.AddDynamic(this , &AMissile::OnOverlapBegin);
		Mesh->OnComponentEndOverlap.AddDynamic(this , &AMissile::OnOverlapEnd);
	}
	RootComponent = Mesh;
	Mesh->SetMobility(EComponentMobility::Movable);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetGenerateOverlapEvents(true);


}

// Called when the game starts or when spawned
void AMissile::BeginPlay()
{
	Super::BeginPlay();
	Particle = LoadObject<UParticleSystem>(nullptr , TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

	
}

// Called every frame
void AMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Magenta , FString::Printf(TEXT("ActorName: %s") , *(Owner->GetName())));
}

void AMissile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult)
{
	//Cast<ABaseChar>(OtherActor) != Owner || Cast<UStaticMeshComponent>(OverlappedComp) != Owner->sphere|| Cast<USkeletalMeshComponent>(OverlappedComp)!=Owner->GetMesh()
	
	if (IsValid(Owner))
	{
		if (OtherActor != Owner)
		{
			//GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::White , TEXT("hh"));
			GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Green , FString::Printf(TEXT("OtherActor: %s") , *(OtherActor->GetName())));
			//GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Red , FString::Printf(TEXT("Owner: %s") , *(Owner->GetName())));
			//GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Black , FString::Printf(TEXT("Owner: %s") , *(Owner->GetName())));

			if (Cast<UStaticMeshComponent>(OverlappedComp))
			{
				GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Magenta , FString::Printf(TEXT("OverlappedComp: %s") , *(OverlappedComp->GetName())));
				float DamageAmount = 100.f;
				FDamageEvent DamageEvent;
				DamageEvent.DamageTypeClass = UDamageType::StaticClass();
				if (IsValid(SettingEmitter))
				{

					SettingEmitter->SetWorldLocation(OtherActor->GetActorLocation());
					UGameplayStatics::ApplyDamage(OtherActor , DamageAmount , nullptr , nullptr , UDamageType::StaticClass());
					SettingEmitter->Activate(true);
					Mesh->SetVisibility(false);
					Mesh->SetSimulatePhysics(false);
					Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

					FTimerManager& TimerManager = GetWorldTimerManager();
					TimerManager.SetTimer(TimerHandle , this , &AMissile::CollisionSet , 2.0f , false);



				}
				else
				{

					SettingEmitter = UGameplayStatics::SpawnEmitterAtLocation(GetWorld() , Particle , OtherActor->GetActorLocation() , FRotator::ZeroRotator , FVector(2.f , 2.f , 2.f) , false , EPSCPoolMethod::None , true);
					UGameplayStatics::ApplyDamage(OtherActor , DamageAmount , nullptr , nullptr , UDamageType::StaticClass());
					Mesh->SetVisibility(false);
					Mesh->SetSimulatePhysics(false);
					Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
					FTimerManager& TimerManager = GetWorldTimerManager();
					TimerManager.SetTimer(TimerHandle , this , &AMissile::CollisionSet , 2.0f , false);


				}
			}
		}
	}	
}

void AMissile::OnOverlapEnd(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex)
{

}

void AMissile::CollisionSet()
{
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
	Mesh->SetVisibility(true);
}

