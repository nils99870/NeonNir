// RuneCharacter.cpp
#include "RuneCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

ARuneCharacter::ARuneCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // --- Camera Boom (3rd person arm) ---
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.f;
    CameraBoom->bUsePawnControlRotation = true; // rotate arm with controller

    // --- Follow Camera ---
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false; // camera follows boom

    // --- Movement setup ---
    bUseControllerRotationYaw = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed; // uses default 600
}

void ARuneCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ARuneCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ARuneCharacter::MoveForward(float Value)
{
    if (!Controller || FMath::IsNearlyZero(Value)) return;

    const FRotator ControlRot = Controller->GetControlRotation();
    const FRotator YawRot(0.f, ControlRot.Yaw, 0.f);
    const FVector  Dir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
    AddMovementInput(Dir, Value);
}

void ARuneCharacter::MoveRight(float Value)
{
    if (!Controller || FMath::IsNearlyZero(Value)) return;

    const FRotator ControlRot = Controller->GetControlRotation();
    const FRotator YawRot(0.f, ControlRot.Yaw, 0.f);
    const FVector  Dir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
    AddMovementInput(Dir, Value);
}

void ARuneCharacter::StartSprint()
{
    bIsSprinting = true;
    GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ARuneCharacter::StopSprint()
{
    bIsSprinting = false;
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ARuneCharacter::MeleeAttack()
{
    UE_LOG(LogTemp, Log, TEXT("Melee Attack"));
    // TODO: Line/Sphere trace for hit detection
}

void ARuneCharacter::CastRune()
{
    UE_LOG(LogTemp, Log, TEXT("Cast Rune"));
    // TODO: Spawn projectile / apply effect
}

void ARuneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Movement
    PlayerInputComponent->BindAxis("MoveForward", this, &ARuneCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ARuneCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

    // Jump
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

    // Sprint
    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ARuneCharacter::StartSprint);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ARuneCharacter::StopSprint);

    // Combat / Abilities
    PlayerInputComponent->BindAction("MeleeAttack", IE_Pressed, this, &ARuneCharacter::MeleeAttack);
    PlayerInputComponent->BindAction("CastRune", IE_Pressed, this, &ARuneCharacter::CastRune);
}
