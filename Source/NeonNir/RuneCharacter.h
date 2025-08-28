#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "RuneCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class NEONNIR_API ARuneCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ARuneCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
    UCameraComponent* FollowCamera;

    UPROPERTY(EditAnywhere, Category="Movement")
    float WalkSpeed = 600.f;

    UPROPERTY(EditAnywhere, Category="Movement")
    float SprintSpeed = 900.f;

    bool bIsSprinting;

    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    /** Enhanced Input mapping context */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(AllowPrivateAccess="true"))
    UInputMappingContext* DefaultMappingContext;

    /** Movement input action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(AllowPrivateAccess="true"))
    UInputAction* MoveAction;

    /** Look input action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(AllowPrivateAccess="true"))
    UInputAction* LookAction;

    /** Jump input action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(AllowPrivateAccess="true"))
    UInputAction* JumpAction;

    /** Sprint input action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(AllowPrivateAccess="true"))
    UInputAction* SprintAction;

    /** Cast rune input action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input", meta=(AllowPrivateAccess="true"))
    UInputAction* CastRuneAction;

    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void StartSprint();
    void StopSprint();

    void CastRune();
};

