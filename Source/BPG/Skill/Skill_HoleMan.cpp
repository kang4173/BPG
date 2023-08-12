// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_HoleMan.h"
#include "Kismet/GameplayStatics.h"

void USkill_HoleMan::BeginPlay()
{
    Super::BeginPlay();


}

void USkill_HoleMan::TickComponent(float DeltaTime , ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime , TickType , ThisTickFunction);
}

void USkill_HoleMan::Tbagging()
{


    if (T_Num == 0)
    {
        Char->SetActorScale3D(FVector(1 , 1 , 0.1));
        T_Num++;
    }
    if (T_Num == 1)
    {
        Char->SetActorScale3D(FVector(1 , 1 , 1));
        T_Num = 0;
    }

}

void USkill_HoleMan::ActiveSkill()
{


    //TArray<AActor*> OverlappingActors;
    //
    ////SnomManSphere->GetOverlappingActors(OverlappingActors , ABaseChar::StaticClass());
    //for (AActor* Actor : OverlappingActors)
    //{
    //    if (Actor->ActorHasTag("Sector1"))
    //    {
    //        float DamageAmount = 100.f;
    //        FDamageEvent DamageEvent;
    //        DamageEvent.DamageTypeClass = UDamageType::StaticClass();
    //        UGameplayStatics::ApplyDamage(Actor , DamageAmount , nullptr , nullptr , UDamageType::StaticClass());
    //    }
    //}
    AHole* tower = GetWorld()->SpawnActor<AHole>(AHole::StaticClass() , FVector((Char->GetActorLocation())-(Char->GetActorForwardVector()*100)) , Char->GetActorRotation());
    
}

void USkill_HoleMan::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar);
    
}
