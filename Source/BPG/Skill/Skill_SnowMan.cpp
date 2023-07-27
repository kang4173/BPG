// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_SnowMan.h"
#include "Kismet/GameplayStatics.h"
#include "BPG/SkillStruct.h"
#include "Components/BoxComponent.h"

USkill_SnowMan::USkill_SnowMan()
{
    UBoxComponent* BoxComponent = NewObject<UBoxComponent>();
}

void USkill_SnowMan::BeginPlay()
{
    Super::BeginPlay();

}

void USkill_SnowMan::TickComponent(float DeltaTime , ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime , TickType , ThisTickFunction);
}

void USkill_SnowMan::Tbagging()
{

    
    if (T_Num == 0)
    {
        Char->SetActorScale3D(FVector(1,1,0.1));
        T_Num++;
    }
    if (T_Num == 1)
    {
        Char->SetActorScale3D(FVector(1 , 1 , 1));
        T_Num = 0;
    }
    
}

void USkill_SnowMan::ActiveSkill()
{

   
    UStaticMeshComponent* SnomManSphere= Char->sphere;
   
    if (!SnomManSphere)
    {
        // 구체 컴포넌트가 없으면 리턴
        return;
    }

    // 겹치는 액터 정보 가져오기
    //TArray<ABaseChar*> OverlappingActors;
    TArray<AActor*> OverlappingActors;
    
    SnomManSphere->GetOverlappingActors(OverlappingActors , ABaseChar::StaticClass());
    for (AActor* Actor : OverlappingActors)
    {
        if (Actor->ActorHasTag("Sector1"))
        {
            float DamageAmount = 100.f;  
            FDamageEvent DamageEvent;
            DamageEvent.DamageTypeClass = UDamageType::StaticClass();
            UGameplayStatics::ApplyDamage(Actor , DamageAmount , nullptr , nullptr , UDamageType::StaticClass());
        }
    }
}

void USkill_SnowMan::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar); 
    Char->sphere->SetRelativeScale3D(FVector(5,5,5));
    //if (Char)
    //{
    //    SpaawnBox();
    //}
}


