// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_JetMan.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

USkill_JetMan::USkill_JetMan()
{
    
}

USkill_JetMan::~USkill_JetMan()
{
   

}

void USkill_JetMan::BeginPlay()
{
    Super::BeginPlay();

    
}

void USkill_JetMan::TickComponent(float DeltaTime , ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime , TickType , ThisTickFunction);
}

void USkill_JetMan::Tbagging()
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

void USkill_JetMan::ActiveSkill()
{
    for (int i=0;i<6;i++)
    { 
        AMissile* Missile;
        FVector Baselocation= ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200));
        FVector SpawnlocationA= ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)+ (Char->GetActorRightVector()*100) - (Char->GetActorUpVector() * 200));
        FVector SpawnlocationB = ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)- (Char->GetActorRightVector()*100) - (Char->GetActorUpVector() * 200));
        FVector SpawnlocationC= ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 400)+ (Char->GetActorRightVector()*100) - (Char->GetActorUpVector() * 300));
        FVector SpawnlocationD = ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 400)- (Char->GetActorRightVector()*100) - (Char->GetActorUpVector() * 300));
        FVector SpawnlocationE= ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 600)+ (Char->GetActorRightVector()*100) - (Char->GetActorUpVector() * 400));
        FVector SpawnlocationF = ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 600)- (Char->GetActorRightVector()*100) - (Char->GetActorUpVector() * 400));
        //FVector SpawnlocationB= ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200));
        FVector BaseRightlocation= ((Char->GetActorLocation()) - (Char->GetActorRightVector() * 200));


        switch (i)
        {
        case 0:
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) - (Char->GetActorForwardVector()*100)).X,- (Char->GetActorRightVector())- (Char->GetActorUpVector()*100) , Char->GetControlRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) - (Char->GetActorRightVector()*200)).X, ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 100)).Y , ((Char->GetActorLocation()) - (Char->GetActorUpVector()*300)).Z) , Char->GetActorRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) - (Char->GetActorForwardVector()*200)).X, ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)).Y-100 , ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)).Z -300) , Char->GetControlRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) - (Char->GetActorForwardVector()*200)).X, ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)).Y-100 , ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)).Z -300) , Char->GetControlRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) - (Char->GetActorForwardVector()*200)).X, (((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200))+ (Char->GetActorRightVector() * 200)).Y , ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)).Z -300) , FRotator(0, Char->GetActorRotation().Yaw ,0));
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) - (Char->GetActorForwardVector()*200)).X, (((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)   + (Char->GetActorRightVector() * 100))).Y , ((Char->GetActorLocation()) - (Char->GetActorRightVector() * 200)).Z ) , FRotator(0 , Char->GetActorRotation().Yaw , 0));
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((((Char->GetActorLocation()) - (Char->GetActorForwardVector()*200)).X, (((Char->GetActorLocation())  - (Char->GetActorForwardVector() * 200))  - (Char->GetActorRightVector() * 100))).Y , (((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)- (Char->GetActorUpVector() * 200)).Z ) , FRotator(0 , Char->GetActorRotation().Yaw , 0));
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Baselocation.X, ((Baselocation) - (Char->GetActorRightVector() * 200)).Y, ((Baselocation-(Char->GetActorUpVector() * 200))).Z), FRotator(Char->GetActorRotation().Yaw , 0 , 0));
            //FVector SpawnlocationA = ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200) + (Char->GetActorRightVector() * 100));
            Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , SpawnlocationA , Char->GetActorRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , Char->GetActorLocation() , Char->GetActorRotation());
            SetOwner(Missile);
            break;
        case 1:
            Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , SpawnlocationB , Char->GetActorRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Baselocation.X, ((Baselocation) + (Char->GetActorRightVector() * 200)).Y, ((Baselocation-(Char->GetActorUpVector() * 200))).Z), FRotator(Char->GetActorRotation().Yaw , 0 , 0));
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((((Char->GetActorLocation()) - (Char->GetActorForwardVector()*200)).X, (((Char->GetActorLocation())  - (Char->GetActorForwardVector() * 200))  - (Char->GetActorRightVector() * 100))).Y , (((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)- (Char->GetActorUpVector() * 200)).Z ) , FRotator(0 , Char->GetActorRotation().Yaw , 0));
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) - (Char->GetActorForwardVector()*200)).X, (((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200))- (Char->GetActorRightVector() * 200)).Y , ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 200)).Z -300) , FRotator(0 , Char->GetActorRotation().Yaw , 0));
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) + (Char->GetActorRightVector()*200)).X, ((Char->GetActorLocation()) - (Char->GetActorForwardVector() * 100)).Y , ((Char->GetActorLocation()) - (Char->GetActorUpVector()*300)).Z) , Char->GetActorRotation());
            //Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Char->GetActorLocation().X-100 , Char->GetActorLocation().Y , Char->GetActorLocation().Z - 200) * Char->GetActorForwardVector() , Char->GetControlRotation());
            SetOwner(Missile);
            //SetOwner(Missile);
            break;
        case 2:
            Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , SpawnlocationC , Char->GetActorRotation());
            //Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Char->GetActorLocation().X+100 , Char->GetActorLocation().Y-100 , Char->GetActorLocation().Z - 230) * Char->GetActorForwardVector() , Char->GetControlRotation());
            SetOwner(Missile);
            break;
        case 3:
            Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , SpawnlocationD , Char->GetActorRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) + (Char->GetActorRightVector()*200)).X, ((Char->GetActorLocation()) - (Char->GetActorForwardVector()*300)).Y , ((Char->GetActorLocation()) - (Char->GetActorUpVector()*300)).Z) , Char->GetActorRotation());
            //Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Char->GetActorLocation().X-100 , Char->GetActorLocation().Y-100 , Char->GetActorLocation().Z - 230) * Char->GetActorForwardVector() , Char->GetControlRotation());
            SetOwner(Missile);
            break;
        case 4:
            Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , SpawnlocationE , Char->GetActorRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) - (Char->GetActorRightVector()*200)).X, ((Char->GetActorLocation()) - (Char->GetActorForwardVector()*500)).Y , ((Char->GetActorLocation()) - (Char->GetActorUpVector()*300)).Z) , Char->GetActorRotation());
            //Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Char->GetActorLocation().X+100 , Char->GetActorLocation().Y-200 , Char->GetActorLocation().Z - 260) * Char->GetActorForwardVector() , Char->GetControlRotation());
            SetOwner(Missile);
            break;
        case 5:
            Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , SpawnlocationF , Char->GetActorRotation());
            //Missile= GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(((Char->GetActorLocation()) + (Char->GetActorRightVector()*200)).X, ((Char->GetActorLocation()) - (Char->GetActorForwardVector()*500)).Y , ((Char->GetActorLocation()) - (Char->GetActorUpVector()*300)).Z) , Char->GetActorRotation());
            //Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Char->GetActorLocation().X-100 , Char->GetActorLocation().Y-200 , Char->GetActorLocation().Z - 260) * Char->GetActorForwardVector() , Char->GetControlRotation());
            SetOwner(Missile);
            break;
        default:
            break;
        }
    }
    //AMissile* Missile = GetWorld()->SpawnActor<AMissile>(AMissile::StaticClass() , FVector(Char->GetActorLocation()) , Char->GetActorRotation());
    //SetOwner(Missile);

}

void USkill_JetMan::CharacterCall(ACharacter* OwnChar)
{
    Char = Cast<ABaseChar>(OwnChar);
    ComSetting();

}

void USkill_JetMan::SetOwner(AMissile* misssile)
{
    misssile->Owner = Char;
    //GEngine->AddOnScreenDebugMessage(-1 , 15 , FColor::White , FString::Printf(TEXT("ActorName: %s") , *(Char->GetName())));
}



void USkill_JetMan::ComSetting_Implementation()
{
    FVector ActorLoaction=Char->GetActorLocation();
    Char->SetActorLocation(FVector(ActorLoaction.X, ActorLoaction.Y, ActorLoaction.Z+1000));
    UCharacterMovementComponent* CharMovement =Char->GetCharacterMovement();
    CharMovement->GravityScale=0;
    //USkeletalMeshComponent* asd= Char->GetMesh();
    CharMovement->MaxAcceleration=15000.0f;
    CharMovement->bUseSeparateBrakingFriction=true;
    CharMovement->BrakingFriction=10000;

}

