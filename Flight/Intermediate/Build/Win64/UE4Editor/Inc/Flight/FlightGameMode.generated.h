// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FLIGHT_FlightGameMode_generated_h
#error "FlightGameMode.generated.h already included, missing '#pragma once' in FlightGameMode.h"
#endif
#define FLIGHT_FlightGameMode_generated_h

#define Flight_Source_Flight_FlightGameMode_h_14_GENERATED_BODY \
	friend FLIGHT_API class UScriptStruct* Z_Construct_UScriptStruct_FScoreToDisplay(); \
	FLIGHT_API static class UScriptStruct* StaticStruct();


#define Flight_Source_Flight_FlightGameMode_h_36_RPC_WRAPPERS
#define Flight_Source_Flight_FlightGameMode_h_36_RPC_WRAPPERS_NO_PURE_DECLS
#define Flight_Source_Flight_FlightGameMode_h_36_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAFlightGameMode(); \
	friend FLIGHT_API class UClass* Z_Construct_UClass_AFlightGameMode(); \
	public: \
	DECLARE_CLASS(AFlightGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, Flight, NO_API) \
	DECLARE_SERIALIZER(AFlightGameMode) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<AFlightGameMode*>(this); }


#define Flight_Source_Flight_FlightGameMode_h_36_INCLASS \
	private: \
	static void StaticRegisterNativesAFlightGameMode(); \
	friend FLIGHT_API class UClass* Z_Construct_UClass_AFlightGameMode(); \
	public: \
	DECLARE_CLASS(AFlightGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, Flight, NO_API) \
	DECLARE_SERIALIZER(AFlightGameMode) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<AFlightGameMode*>(this); }


#define Flight_Source_Flight_FlightGameMode_h_36_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFlightGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFlightGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFlightGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFlightGameMode); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AFlightGameMode(const AFlightGameMode& InCopy); \
public:


#define Flight_Source_Flight_FlightGameMode_h_36_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AFlightGameMode(const AFlightGameMode& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFlightGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFlightGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFlightGameMode)


#define Flight_Source_Flight_FlightGameMode_h_33_PROLOG
#define Flight_Source_Flight_FlightGameMode_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Flight_Source_Flight_FlightGameMode_h_36_RPC_WRAPPERS \
	Flight_Source_Flight_FlightGameMode_h_36_INCLASS \
	Flight_Source_Flight_FlightGameMode_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Flight_Source_Flight_FlightGameMode_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Flight_Source_Flight_FlightGameMode_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	Flight_Source_Flight_FlightGameMode_h_36_INCLASS_NO_PURE_DECLS \
	Flight_Source_Flight_FlightGameMode_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Flight_Source_Flight_FlightGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
