#include "Characters/RuneCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

ARuneCharacter::ARuneCharacter()
{
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom);

    WalkSpeed = 600.f;
    SprintSpeed = 900.f;
    bIsSprinting = false;
}

void ARuneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInput->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ARuneCharacter::MoveForward);
        EnhancedInput->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ARuneCharacter::MoveRight);
        EnhancedInput->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ARuneCharacter::Turn);
        EnhancedInput->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &ARuneCharacter::LookUp);
        EnhancedInput->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ARuneCharacter::Jump);
        EnhancedInput->BindAction(SprintAction, ETriggerEvent::Triggered, this, &ARuneCharacter::Sprint);
        EnhancedInput->BindAction(CastRuneAction, ETriggerEvent::Triggered, this, &ARuneCharacter::CastRune);
    }
}

void ARuneCharacter::MoveForward(const FInputActionValue& Value)
{
    const float Axis = Value.Get<float>();
    if (Axis != 0.f)
    {
        AddMovementInput(GetActorForwardVector(), Axis);
    }
}

void ARuneCharacter::MoveRight(const FInputActionValue& Value)
{
    const float Axis = Value.Get<float>();
    if (Axis != 0.f)
    {
        AddMovementInput(GetActorRightVector(), Axis);
    }
}

void ARuneCharacter::Turn(const FInputActionValue& Value)
{
    AddControllerYawInput(Value.Get<float>());
}

void ARuneCharacter::LookUp(const FInputActionValue& Value)
{
    AddControllerPitchInput(Value.Get<float>());
}

void ARuneCharacter::Sprint()
{
    bIsSprinting = !bIsSprinting;
    if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
    {
        MoveComp->MaxWalkSpeed = bIsSprinting ? SprintSpeed : WalkSpeed;
    }
}

void ARuneCharacter::CastRune()
{
    // TODO: Implement rune casting logic
}
