// RuneCharacter.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RuneCharacter.generated.h"
class USpringArmComponent;
class UCameraComponent;


UCLASS()
class NEONNIR_API ARuneCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ARuneCharacter();

protected:
    virtual void BeginPlay() override;

    // === Movement ===
    void MoveForward(float Value);
    void MoveRight(float Value);
    void StartSprint();
    void StopSprint();

    // === Combat / Abilities ===
    void MeleeAttack();
    void CastRune();

    // === Camera ===
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    class UCameraComponent* FollowCamera;

    // === Tunables ===
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float WalkSpeed = 600.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float SprintSpeed = 1000.f;

    bool bIsSprinting = false;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
