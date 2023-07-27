// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackTower.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AAttackTower::AAttackTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshCom=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SM_StaticMeshComponent(TEXT("StaticMesh'/Game/StarterContent/Props/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02'"));
	RootComponent = StaticMeshCom;
	Box = CreateDefaultSubobject< UBoxComponent>(TEXT("Box"));
	if (SM_StaticMeshComponent.Succeeded())
	{
		StaticMeshCom->SetStaticMesh(SM_StaticMeshComponent.Object);
		Box->SetupAttachment(StaticMeshCom);
		Box->SetCollisionProfileName(FName(TEXT("OverlapAll")));
		StaticMeshCom->SetCollisionProfileName(FName(TEXT("OverlapAll")));
		Box->SetWorldScale3D(FVector(10 , 10 , 2.5f));


		Box->OnComponentBeginOverlap.AddDynamic(this , &AAttackTower::OnOverlapBegin);
		Box->OnComponentEndOverlap.AddDynamic(this , &AAttackTower::OnOverlapEnd);


	}
	//static ConstructorHelpers::FObjectFinder<UParticleSystem>ExParticle(TEXT("C:/Users/gkgk0/Documents/Unreal Projects/BPG/Content/StarterContent/Particles/P_Explosion.uasset"));
	//static ConstructorHelpers::FClassFinder<UParticleSystem>ExParticle(TEXT("C:/Users/gkgk0/Documents/Unreal Projects/BPG/Content/StarterContent/Particles/P_Explosion.uasset"));
	////Particle->AddReferencedObjects();
	//if (ExParticle.Succeeded())
	//{
	//	
	//}
	//Particle->PostLoad(TEXT("C:/Users/gkgk0/Documents/Unreal Projects/BPG/Content/StarterContent/Particles/P_Explosion.uasset");
}

// Called when the game starts or when spawned
void AAttackTower::BeginPlay()
{
	Particle = LoadObject<UParticleSystem>(nullptr , TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	Super::BeginPlay();
	
}

// Called every frame
void AAttackTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Cooldown)
	{ 
		AttackTimeAcc += DeltaTime;
		if (AttackTimeAcc >= AttackInterval)
		{
			AttackTimeAcc = 0;
			Cooldown = false;
			
		}
	}
	else
	{
		Attack();
	}
}

void AAttackTower::Attack()
{
	if (AttackArr.Num())
	{
		TArray<AActor*> OverlappingActors;

		Box->GetOverlappingActors(OverlappingActors , ABaseChar::StaticClass());
		for (AActor* Actor : OverlappingActors)
		{
			if (Owner== Actor)
			{

			}
			else
			{
				float DamageAmount = 100.f;
				FDamageEvent DamageEvent;
				DamageEvent.DamageTypeClass = UDamageType::StaticClass();
				if (IsValid(SettingEmitter))
				{

					SettingEmitter->SetWorldLocation(Actor->GetActorLocation());
					UGameplayStatics::ApplyDamage(Actor , DamageAmount , nullptr , nullptr , UDamageType::StaticClass());
					SettingEmitter->Activate(true);
					Cooldown = true;

				}
				else
				{

					SettingEmitter = UGameplayStatics::SpawnEmitterAtLocation(GetWorld() , Particle , Actor->GetActorLocation() , FRotator::ZeroRotator , FVector(1.f , 1.f , 1.f) , false , EPSCPoolMethod::None , true);
					UGameplayStatics::ApplyDamage(Actor , DamageAmount , nullptr , nullptr , UDamageType::StaticClass());
					Cooldown = true;

				}
			}
			
		}
		

	}
}

void AAttackTower::OnOverlapBegin(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFromSweep , const FHitResult& SweepResult)
{
	ABaseChar* OverlapChar = Cast<ABaseChar>(OtherActor);
	if (OverlapChar)
	{
		AttackArr.Add(OverlapChar);
		

	}

}

void AAttackTower::OnOverlapEnd(UPrimitiveComponent* OverlappedComp , AActor* OtherActor , UPrimitiveComponent* OtherComp , int32 OtherBodyIndex)
{
	ABaseChar* OverlapChar = Cast<ABaseChar>(OtherActor);
	if (OverlapChar)
	{
		AttackArr.Remove(OverlapChar);

	}
}