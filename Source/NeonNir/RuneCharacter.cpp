#include "RuneCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"

ARuneCharacter::ARuneCharacter()
{
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.f;
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    bIsSprinting = false;
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ARuneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ARuneCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ARuneCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &ARuneCharacter::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &ARuneCharacter::LookUp);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ARuneCharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ARuneCharacter::StopJumping);
    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ARuneCharacter::StartSprint);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ARuneCharacter::StopSprint);
}

void ARuneCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ARuneCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void ARuneCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void ARuneCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
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

void ARuneCharacter::CastRune()
{
    UE_LOG(LogTemp, Log, TEXT("Casting Rune"));
}

