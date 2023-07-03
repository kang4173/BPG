// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseChar.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABaseChar::ABaseChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; 	
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	sphere->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MyMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (MyMesh.Succeeded())
	{
		sphere->SetStaticMesh(MyMesh.Object);
	}

	BaseSkill = CreateDefaultSubobject<USkillComp>(TEXT("BaseSkill"));

	khj = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/BPG/KHJ/Base/khj.khj'"));
	kkk = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/BPG/KHJ/Base/kkk.kkk'"));
}

// Called when the game starts or when spawned
void ABaseChar::BeginPlay()
{
	Super::BeginPlay();

	RowName = khj->GetRowNames();

	ChangeChar();
}

// Called every frame
void ABaseChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseChar::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseChar::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABaseChar::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABaseChar::LookUpAtRate);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ABaseChar::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ABaseChar::TouchStopped);
}

void ABaseChar::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ABaseChar::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ABaseChar::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABaseChar::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABaseChar::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ABaseChar::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ABaseChar::ChangeChar()
{
	ResetCharSpeed();

	BaseSkill->DestroyComponent();

	RandomNum = RowName[FMath::RandRange(MINCOUNT, MAXCOUNT)];

	MainST = *(khj->FindRow<FMainStruct>(RandomNum, FString("")));

	if (&MainST)
	{
		BaseSkill = Cast<USkillComp>(AddComponentByClass(MainST.BaseSkillComp, true, GetTransform(), false));
	}
	else { GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, TEXT("MainST Null")); }

	if (BaseSkill)
	{
		BaseSkill->SKillST = *(kkk->FindRow<FSkillStruct>(RandomNum, FString("")));
		BaseSkill->CharacterCall(this); 
	}
	else { GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, TEXT("BaseSkill Null")); }

}