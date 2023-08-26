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
    FTransform SpawnTransform=FTransform(FRotator(),FVector(),FVector());
    FVector SettingLocation= FVector((Char->GetActorLocation()) + (Char->GetActorForwardVector() * 1000));
    //AHole* tower = GetWorld()->SpawnActor<AHole>(AHole::StaticClass() , FVector(SettingLocation.X, SettingLocation.Y, SettingLocation.Z-90) , Char->GetActorRotation());
    //AHole* Hole = GetWorld()->SpawnActor<AHole>(AHole::StaticClass() , FTransform(FRotator(0,0,0),FVector(SettingLocation.X , SettingLocation.Y , SettingLocation.Z - 90), FVector(1,1,1)));
    AHole* Hole = GetWorld()->SpawnActor<AHole>(AHole::StaticClass() , FTransform(FRotator(0 , 0 , 0),FVector(Char->GetActorLocation().X, Char->GetActorLocation().Y, Char->GetActorLocation().Z+80), FVector(1 , 1 , 1)));
    FVector Force = FVector((Hole->GetActorLocation()) + (Char->GetActorForwardVector() * 1000000) + (Char->GetActorUpVector() * 1000000));
    Hole->Mesh->AddForce(Force);
    //GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::Magenta, FString::Printf(TEXT("HoleManActive") ));

}

void USkill_HoleMan::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar);
    
}

void USkill_HoleMan::SetOwner(AHole* Hole)
{
    Hole->Owner = Char;
}