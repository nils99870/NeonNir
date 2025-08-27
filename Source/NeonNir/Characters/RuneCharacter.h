#pragma once

#include "GameFramework/Character.h"
#include "RuneCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

UCLASS()
class NEONNIR_API ARuneCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ARuneCharacter();

protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    UCameraComponent* FollowCamera;

    UPROPERTY(EditDefaultsOnly, Category="Input")
    UInputAction* MoveForwardAction;

    UPROPERTY(EditDefaultsOnly, Category="Input")
    UInputAction* MoveRightAction;

    UPROPERTY(EditDefaultsOnly, Category="Input")
    UInputAction* TurnAction;

    UPROPERTY(EditDefaultsOnly, Category="Input")
    UInputAction* LookUpAction;

    UPROPERTY(EditDefaultsOnly, Category="Input")
    UInputAction* JumpAction;

    UPROPERTY(EditDefaultsOnly, Category="Input")
    UInputAction* SprintAction;

    UPROPERTY(EditDefaultsOnly, Category="Input")
    UInputAction* CastRuneAction;

    UFUNCTION()
    void MoveForward(const FInputActionValue& Value);

    UFUNCTION()
    void MoveRight(const FInputActionValue& Value);

    UFUNCTION()
    void Turn(const FInputActionValue& Value);

    UFUNCTION()
    void LookUp(const FInputActionValue& Value);

    UFUNCTION()
    void Sprint();

    UFUNCTION()
    void CastRune();

private:
    bool bIsSprinting;
    float WalkSpeed;
    float SprintSpeed;
};
