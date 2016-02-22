// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "Flight.h"
#include "Flight.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlight() {}
	void AFlightBullet::StaticRegisterNativesAFlightBullet()
	{
	}
	IMPLEMENT_CLASS(AFlightBullet, 2980958513);
	void AFlightGameMode::StaticRegisterNativesAFlightGameMode()
	{
	}
	IMPLEMENT_CLASS(AFlightGameMode, 2900729568);
	void AFlightPowerUp::StaticRegisterNativesAFlightPowerUp()
	{
		FNativeFunctionRegistrar::RegisterFunction(AFlightPowerUp::StaticClass(),"OnBeginOverlap",(Native)&AFlightPowerUp::execOnBeginOverlap);
	}
	IMPLEMENT_CLASS(AFlightPowerUp, 3588960654);
	void AFlightWeapon::StaticRegisterNativesAFlightWeapon()
	{
	}
	IMPLEMENT_CLASS(AFlightWeapon, 1146313973);
	void ABasicWeapon::StaticRegisterNativesABasicWeapon()
	{
	}
	IMPLEMENT_CLASS(ABasicWeapon, 1250205333);
	void APaperPlayerShip::StaticRegisterNativesAPaperPlayerShip()
	{
	}
	IMPLEMENT_CLASS(APaperPlayerShip, 2997559567);
	void APlayerShip::StaticRegisterNativesAPlayerShip()
	{
	}
	IMPLEMENT_CLASS(APlayerShip, 3715695009);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AGameMode();
	ENGINE_API class UClass* Z_Construct_UClass_AActor_NoRegister();
	PAPER2D_API class UClass* Z_Construct_UClass_APaperCharacter();
	ENGINE_API class UClass* Z_Construct_UClass_APawn();

	FLIGHT_API class UClass* Z_Construct_UClass_AFlightBullet_NoRegister();
	FLIGHT_API class UClass* Z_Construct_UClass_AFlightBullet();
	FLIGHT_API class UClass* Z_Construct_UClass_AFlightGameMode_NoRegister();
	FLIGHT_API class UClass* Z_Construct_UClass_AFlightGameMode();
	FLIGHT_API class UFunction* Z_Construct_UFunction_AFlightPowerUp_OnBeginOverlap();
	FLIGHT_API class UClass* Z_Construct_UClass_AFlightPowerUp_NoRegister();
	FLIGHT_API class UClass* Z_Construct_UClass_AFlightPowerUp();
	FLIGHT_API class UClass* Z_Construct_UClass_AFlightWeapon_NoRegister();
	FLIGHT_API class UClass* Z_Construct_UClass_AFlightWeapon();
	FLIGHT_API class UClass* Z_Construct_UClass_ABasicWeapon_NoRegister();
	FLIGHT_API class UClass* Z_Construct_UClass_ABasicWeapon();
	FLIGHT_API class UClass* Z_Construct_UClass_APaperPlayerShip_NoRegister();
	FLIGHT_API class UClass* Z_Construct_UClass_APaperPlayerShip();
	FLIGHT_API class UClass* Z_Construct_UClass_APlayerShip_NoRegister();
	FLIGHT_API class UClass* Z_Construct_UClass_APlayerShip();
	FLIGHT_API class UPackage* Z_Construct_UPackage_Flight();
	UClass* Z_Construct_UClass_AFlightBullet_NoRegister()
	{
		return AFlightBullet::StaticClass();
	}
	UClass* Z_Construct_UClass_AFlightBullet()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_Flight();
			OuterClass = AFlightBullet::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_Collider = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Collider"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(Collider, AFlightBullet), 0x00000800000a0009, Z_Construct_UClass_USphereComponent_NoRegister());
				UProperty* NewProp_Mesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Mesh"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(Mesh, AFlightBullet), 0x00000800000a0009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
				UProperty* NewProp_MovementComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MovementComponent"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(MovementComponent, AFlightBullet), 0x00000800000a0009, Z_Construct_UClass_UProjectileMovementComponent_NoRegister());
				UProperty* NewProp_TimeTillDeath = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("TimeTillDeath"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(TimeTillDeath, AFlightBullet), 0x0000000000000001);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Bullets/FlightBullet.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Bullets/FlightBullet.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("I will be turning this into an Abstract class when types of bullets are decided."));
				MetaData->SetValue(NewProp_Collider, TEXT("Category"), TEXT("FlightBullet"));
				MetaData->SetValue(NewProp_Collider, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Collider, TEXT("ModuleRelativePath"), TEXT("Bullets/FlightBullet.h"));
				MetaData->SetValue(NewProp_Mesh, TEXT("Category"), TEXT("FlightBullet"));
				MetaData->SetValue(NewProp_Mesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Mesh, TEXT("ModuleRelativePath"), TEXT("Bullets/FlightBullet.h"));
				MetaData->SetValue(NewProp_MovementComponent, TEXT("Category"), TEXT("FlightBullet"));
				MetaData->SetValue(NewProp_MovementComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_MovementComponent, TEXT("ModuleRelativePath"), TEXT("Bullets/FlightBullet.h"));
				MetaData->SetValue(NewProp_TimeTillDeath, TEXT("Category"), TEXT("FlightBullet"));
				MetaData->SetValue(NewProp_TimeTillDeath, TEXT("ModuleRelativePath"), TEXT("Bullets/FlightBullet.h"));
				MetaData->SetValue(NewProp_TimeTillDeath, TEXT("ToolTip"), TEXT("When the bullet will kill its self"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFlightBullet(Z_Construct_UClass_AFlightBullet, TEXT("AFlightBullet"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFlightBullet);
	UClass* Z_Construct_UClass_AFlightGameMode_NoRegister()
	{
		return AFlightGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_AFlightGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameMode();
			Z_Construct_UPackage_Flight();
			OuterClass = AFlightGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x2090028C;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("FlightGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("FlightGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFlightGameMode(Z_Construct_UClass_AFlightGameMode, TEXT("AFlightGameMode"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFlightGameMode);
	UFunction* Z_Construct_UFunction_AFlightPowerUp_OnBeginOverlap()
	{
		struct FlightPowerUp_eventOnBeginOverlap_Parms
		{
			AActor* OtherActor;
		};
		UObject* Outer=Z_Construct_UClass_AFlightPowerUp();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnBeginOverlap"), RF_Public|RF_Transient|RF_Native) UFunction(FObjectInitializer(), NULL, 0x00020400, 65535, sizeof(FlightPowerUp_eventOnBeginOverlap_Parms));
			UProperty* NewProp_OtherActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherActor"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(OtherActor, FlightPowerUp_eventOnBeginOverlap_Parms), 0x0000000000000080, Z_Construct_UClass_AActor_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Power Ups/FlightPowerUp.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Each Power Up will override this function to give the appropriate effects to the player. It will ONLY fire when the power up overlaps with the player."));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFlightPowerUp_NoRegister()
	{
		return AFlightPowerUp::StaticClass();
	}
	UClass* Z_Construct_UClass_AFlightPowerUp()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_Flight();
			OuterClass = AFlightPowerUp::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900081;

				OuterClass->LinkChild(Z_Construct_UFunction_AFlightPowerUp_OnBeginOverlap());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_Collider = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Collider"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(Collider, AFlightPowerUp), 0x0000080000090009, Z_Construct_UClass_USphereComponent_NoRegister());
				UProperty* NewProp_Mesh = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Mesh"), RF_Public|RF_Transient|RF_Native) UObjectProperty(CPP_PROPERTY_BASE(Mesh, AFlightPowerUp), 0x0000080000090009, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMap(Z_Construct_UFunction_AFlightPowerUp_OnBeginOverlap()); // 3720292695
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Power Ups/FlightPowerUp.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Power Ups/FlightPowerUp.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("Pure Virtual class  for the power ups each will inherit from this class and override the OnBeginOverlap function for their functionality"));
				MetaData->SetValue(NewProp_Collider, TEXT("Category"), TEXT("FlightPowerUp"));
				MetaData->SetValue(NewProp_Collider, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Collider, TEXT("ModuleRelativePath"), TEXT("Power Ups/FlightPowerUp.h"));
				MetaData->SetValue(NewProp_Mesh, TEXT("Category"), TEXT("FlightPowerUp"));
				MetaData->SetValue(NewProp_Mesh, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Mesh, TEXT("ModuleRelativePath"), TEXT("Power Ups/FlightPowerUp.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFlightPowerUp(Z_Construct_UClass_AFlightPowerUp, TEXT("AFlightPowerUp"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFlightPowerUp);
	UClass* Z_Construct_UClass_AFlightWeapon_NoRegister()
	{
		return AFlightWeapon::StaticClass();
	}
	UClass* Z_Construct_UClass_AFlightWeapon()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage_Flight();
			OuterClass = AFlightWeapon::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900081;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_FireRate = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FireRate"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(FireRate, AFlightWeapon), 0x0000080000010001);
				UProperty* NewProp_ProjectileClass = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ProjectileClass"), RF_Public|RF_Transient|RF_Native) UClassProperty(CPP_PROPERTY_BASE(ProjectileClass, AFlightWeapon), 0x0004080000000000, Z_Construct_UClass_AFlightBullet_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Weapons/FlightWeapon.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Weapons/FlightWeapon.h"));
				MetaData->SetValue(NewProp_FireRate, TEXT("Category"), TEXT("FlightWeapon"));
				MetaData->SetValue(NewProp_FireRate, TEXT("ModuleRelativePath"), TEXT("Weapons/FlightWeapon.h"));
				MetaData->SetValue(NewProp_ProjectileClass, TEXT("ModuleRelativePath"), TEXT("Weapons/FlightWeapon.h"));
				MetaData->SetValue(NewProp_ProjectileClass, TEXT("ToolTip"), TEXT("The type of bullet that will get spawned"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFlightWeapon(Z_Construct_UClass_AFlightWeapon, TEXT("AFlightWeapon"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFlightWeapon);
	UClass* Z_Construct_UClass_ABasicWeapon_NoRegister()
	{
		return ABasicWeapon::StaticClass();
	}
	UClass* Z_Construct_UClass_ABasicWeapon()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AFlightWeapon();
			Z_Construct_UPackage_Flight();
			OuterClass = ABasicWeapon::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("Weapons/BasicWeapon.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Weapons/BasicWeapon.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABasicWeapon(Z_Construct_UClass_ABasicWeapon, TEXT("ABasicWeapon"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABasicWeapon);
	UClass* Z_Construct_UClass_APaperPlayerShip_NoRegister()
	{
		return APaperPlayerShip::StaticClass();
	}
	UClass* Z_Construct_UClass_APaperPlayerShip()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APaperCharacter();
			Z_Construct_UPackage_Flight();
			OuterClass = APaperPlayerShip::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PaperPlayerShip.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PaperPlayerShip.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APaperPlayerShip(Z_Construct_UClass_APaperPlayerShip, TEXT("APaperPlayerShip"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(APaperPlayerShip);
	UClass* Z_Construct_UClass_APlayerShip_NoRegister()
	{
		return APlayerShip::StaticClass();
	}
	UClass* Z_Construct_UClass_APlayerShip()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_APawn();
			Z_Construct_UPackage_Flight();
			OuterClass = APlayerShip::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("PlayerShip.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("PlayerShip.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayerShip(Z_Construct_UClass_APlayerShip, TEXT("APlayerShip"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerShip);
	UPackage* Z_Construct_UPackage_Flight()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/Flight")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x34B13AED;
			Guid.B = 0xA228EE74;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
