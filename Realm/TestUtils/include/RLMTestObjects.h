////////////////////////////////////////////////////////////////////////////
//
// Copyright 2014 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Realm/Realm.h>

#if __has_extension(objc_generics)
#define RLM_GENERIC_ARRAY(CLASS) RLMArray<CLASS *><CLASS>
#define RLM_GENERIC_SET(CLASS) RLMSet<CLASS *><CLASS>
#else
#define RLM_GENERIC_ARRAY(CLASS) RLMArray<CLASS>
#define RLM_GENERIC_SET(CLASS) RLMSet<CLASS>
#endif

#pragma mark - Abstract Objects
#pragma mark -

#pragma mark SingleTypeObjects

@interface StringObject : RLMObject

@property NSString *stringCol;

@end

@interface IntObject : RLMObject

@property int intCol;

@end

@interface AllIntSizesObject : RLMObject
// int8_t not supported due to being ambiguous with BOOL

@property int16_t int16;
@property int32_t int32;
@property int64_t int64;

@end

@interface FloatObject : RLMObject

@property float floatCol;

@end

@interface DoubleObject : RLMObject

@property double doubleCol;

@end

@interface BoolObject : RLMObject

@property BOOL boolCol;

@end

@interface DateObject : RLMObject

@property NSDate *dateCol;

@end

@interface BinaryObject : RLMObject

@property NSData *binaryCol;

@end

@interface DecimalObject : RLMObject
@property RLMDecimal128 *decimalCol;
@end

@interface UTF8Object : RLMObject
@property NSString *柱колоéнǢкƱаم;
@end

@interface IndexedStringObject : RLMObject
@property NSString *stringCol;
@end

RLM_COLLECTION_TYPE(StringObject)
RLM_COLLECTION_TYPE(IntObject)

@interface LinkStringObject : RLMObject
@property StringObject *objectCol;
@end

@interface LinkIndexedStringObject : RLMObject
@property IndexedStringObject *objectCol;
@end

@interface RequiredPropertiesObject : RLMObject
@property NSString *stringCol;
@property NSData *binaryCol;
@property NSDate *dateCol;
@end

@interface IgnoredURLObject : RLMObject
@property NSString *name;
@property NSURL *url;
@end

@interface EmbeddedIntObject : RLMEmbeddedObject
@property int intCol;
@end
RLM_COLLECTION_TYPE(EmbeddedIntObject)

@interface EmbeddedIntParentObject : RLMObject
@property int pk;
@property EmbeddedIntObject *object;
@property RLMArray<EmbeddedIntObject> *array;
@end

@interface UuidObject: RLMObject
@property NSUUID *uuidCol;
@end

@interface MixedObject: RLMObject
@property id<RLMValue> anyCol;
@property RLMArray<RLMValue> *anyArray;

@end

#pragma mark AllTypesObject

@interface AllTypesObject : RLMObject

@property BOOL          boolCol;
@property int           intCol;
@property float         floatCol;
@property double        doubleCol;
@property NSString     *stringCol;
@property NSData       *binaryCol;
@property NSDate       *dateCol;
@property bool          cBoolCol;
@property int64_t       longCol;
@property RLMDecimal128 *decimalCol;
@property RLMObjectId  *objectIdCol;
@property NSUUID       *uuidCol;
@property StringObject *objectCol;
@property MixedObject  *mixedObjectCol;
@property (readonly) RLMLinkingObjects *linkingObjectsCol;
@property id<RLMValue> anyCol;

+ (NSDictionary *)values:(int)i stringObject:(StringObject *)so;
+ (NSDictionary *)values:(int)i
            stringObject:(StringObject *)so
             mixedObject:(MixedObject *)mo;

@end

RLM_COLLECTION_TYPE(AllTypesObject)

@interface LinkToAllTypesObject : RLMObject
@property AllTypesObject *allTypesCol;
@end

@interface ArrayOfAllTypesObject : RLMObject
@property RLM_GENERIC_ARRAY(AllTypesObject) *array;
@end

@interface SetOfAllTypesObject : RLMObject
@property RLM_GENERIC_SET(AllTypesObject) *set;
@end

@interface AllOptionalTypes : RLMObject
@property NSNumber<RLMInt> *intObj;
@property NSNumber<RLMFloat> *floatObj;
@property NSNumber<RLMDouble> *doubleObj;
@property NSNumber<RLMBool> *boolObj;
@property NSString *string;
@property NSData *data;
@property NSDate *date;
@property RLMDecimal128 *decimal;
@property RLMObjectId *objectId;
@property NSUUID *uuidCol;
@end

@interface AllOptionalTypesPK : RLMObject
@property int pk;

@property NSNumber<RLMInt> *intObj;
@property NSNumber<RLMFloat> *floatObj;
@property NSNumber<RLMDouble> *doubleObj;
@property NSNumber<RLMBool> *boolObj;
@property NSString *string;
@property NSData *data;
@property NSDate *date;
@property RLMDecimal128 *decimal;
@property RLMObjectId *objectId;
@property NSUUID *uuidCol;
@end

@interface AllPrimitiveArrays : RLMObject
@property RLMArray<RLMInt> *intObj;
@property RLMArray<RLMFloat> *floatObj;
@property RLMArray<RLMDouble> *doubleObj;
@property RLMArray<RLMBool> *boolObj;
@property RLMArray<RLMString> *stringObj;
@property RLMArray<RLMDate> *dateObj;
@property RLMArray<RLMData> *dataObj;
@property RLMArray<RLMDecimal128> *decimalObj;
@property RLMArray<RLMObjectId> *objectIdObj;
@property RLMArray<RLMUUID> *uuidObj;
@property RLMArray<RLMValue> *anyObj1;
@property RLMArray<RLMValue> *anyObj2;
@property RLMArray<RLMValue> *anyObj3;
@property RLMArray<RLMValue> *anyObj4;
@property RLMArray<RLMValue> *anyObj5;
@property RLMArray<RLMValue> *anyObj6;
@property RLMArray<RLMValue> *anyObj7;
@property RLMArray<RLMValue> *anyObj8;
@property RLMArray<RLMValue> *anyObj9;
@property RLMArray<RLMValue> *anyObj10;
@end

@interface AllOptionalPrimitiveArrays : RLMObject
@property RLMArray<RLMInt> *intObj;
@property RLMArray<RLMFloat> *floatObj;
@property RLMArray<RLMDouble> *doubleObj;
@property RLMArray<RLMBool> *boolObj;
@property RLMArray<RLMString> *stringObj;
@property RLMArray<RLMDate> *dateObj;
@property RLMArray<RLMData> *dataObj;
@property RLMArray<RLMDecimal128> *decimalObj;
@property RLMArray<RLMObjectId> *objectIdObj;
@property RLMArray<RLMUUID> *uuidObj;
@end

@interface AllPrimitiveSets : RLMObject
@property RLMSet<RLMInt> *intObj;
@property RLMSet<RLMInt> *intObj2;
@property RLMSet<RLMFloat> *floatObj;
@property RLMSet<RLMFloat> *floatObj2;
@property RLMSet<RLMDouble> *doubleObj;
@property RLMSet<RLMDouble> *doubleObj2;
@property RLMSet<RLMBool> *boolObj;
@property RLMSet<RLMBool> *boolObj2;
@property RLMSet<RLMString> *stringObj;
@property RLMSet<RLMString> *stringObj2;
@property RLMSet<RLMDate> *dateObj;
@property RLMSet<RLMDate> *dateObj2;
@property RLMSet<RLMData> *dataObj;
@property RLMSet<RLMData> *dataObj2;
@property RLMSet<RLMDecimal128> *decimalObj;
@property RLMSet<RLMDecimal128> *decimalObj2;
@property RLMSet<RLMObjectId> *objectIdObj;
@property RLMSet<RLMObjectId> *objectIdObj2;
@property RLMSet<RLMUUID> *uuidObj;
@property RLMSet<RLMUUID> *uuidObj2;

@property RLMSet<RLMValue> *anyObjA;
@property RLMSet<RLMValue> *anyObjA2;
@property RLMSet<RLMValue> *anyObjB;
@property RLMSet<RLMValue> *anyObjB2;
@property RLMSet<RLMValue> *anyObjC;
@property RLMSet<RLMValue> *anyObjC2;
@property RLMSet<RLMValue> *anyObjD;
@property RLMSet<RLMValue> *anyObjD2;
@property RLMSet<RLMValue> *anyObjE;
@property RLMSet<RLMValue> *anyObjE2;
@property RLMSet<RLMValue> *anyObjF;
@property RLMSet<RLMValue> *anyObjF2;
@property RLMSet<RLMValue> *anyObjG;
@property RLMSet<RLMValue> *anyObjG2;
@property RLMSet<RLMValue> *anyObjH;
@property RLMSet<RLMValue> *anyObjH2;
@property RLMSet<RLMValue> *anyObjI;
@property RLMSet<RLMValue> *anyObjI2;
@property RLMSet<RLMValue> *anyObjJ;
@property RLMSet<RLMValue> *anyObjJ2;
@end

@interface AllOptionalPrimitiveSets : RLMObject
@property RLMSet<RLMInt> *intObj;
@property RLMSet<RLMInt> *intObj2;
@property RLMSet<RLMFloat> *floatObj;
@property RLMSet<RLMFloat> *floatObj2;
@property RLMSet<RLMDouble> *doubleObj;
@property RLMSet<RLMDouble> *doubleObj2;
@property RLMSet<RLMBool> *boolObj;
@property RLMSet<RLMBool> *boolObj2;
@property RLMSet<RLMString> *stringObj;
@property RLMSet<RLMString> *stringObj2;
@property RLMSet<RLMDate> *dateObj;
@property RLMSet<RLMDate> *dateObj2;
@property RLMSet<RLMData> *dataObj;
@property RLMSet<RLMData> *dataObj2;
@property RLMSet<RLMDecimal128> *decimalObj;
@property RLMSet<RLMDecimal128> *decimalObj2;
@property RLMSet<RLMObjectId> *objectIdObj;
@property RLMSet<RLMObjectId> *objectIdObj2;
@property RLMSet<RLMUUID> *uuidObj;
@property RLMSet<RLMUUID> *uuidObj2;
@end

@interface AllPrimitiveRLMValues : RLMObject
@property id<RLMValue> nullVal;
@property id<RLMValue> intVal;
@property id<RLMValue> floatVal;
@property id<RLMValue> doubleVal;
@property id<RLMValue> boolVal;
@property id<RLMValue> stringVal;
@property id<RLMValue> dateVal;
@property id<RLMValue> dataVal;
@property id<RLMValue> decimalVal;
@property id<RLMValue> objectIdVal;
@property id<RLMValue> uuidVal;
@end

#pragma mark - Real Life Objects
#pragma mark -

#pragma mark EmployeeObject

@interface EmployeeObject : RLMObject

@property NSString *name;
@property int age;
@property BOOL hired;

@end

RLM_COLLECTION_TYPE(EmployeeObject)

#pragma mark CompanyObject

@interface CompanyObject : RLMObject

@property NSString *name;
@property RLM_GENERIC_ARRAY(EmployeeObject) *employees;
@property RLM_GENERIC_SET(EmployeeObject) *employeeSet;

@end

#pragma mark LinkToCompanyObject

@interface LinkToCompanyObject : RLMObject

@property CompanyObject *company;

@end

#pragma mark DogObject

@interface DogObject : RLMObject
@property NSString *dogName;
@property int age;
@property (readonly) RLMLinkingObjects *owners;
@end

RLM_COLLECTION_TYPE(DogObject)

@interface DogArrayObject : RLMObject
@property RLM_GENERIC_ARRAY(DogObject) *dogs;
@end

@interface DogSetObject : RLMObject
@property RLM_GENERIC_SET(DogObject) *dogs;
@end

#pragma mark OwnerObject

@interface OwnerObject : RLMObject

@property NSString *name;
@property DogObject *dog;

@end

#pragma mark - Specific Use Objects
#pragma mark -

#pragma mark CustomAccessorsObject

@interface CustomAccessorsObject : RLMObject

@property (getter = getThatName) NSString *name;
@property (setter = setTheInt:)  int age;

@end

#pragma mark BaseClassStringObject

@interface BaseClassStringObject : RLMObject

@property int intCol;

@end

@interface BaseClassStringObject ()

@property NSString *stringCol;

@end

#pragma mark CircleObject

@interface CircleObject : RLMObject

@property NSString *data;
@property CircleObject *next;

@end

RLM_COLLECTION_TYPE(CircleObject);

#pragma mark CircleArrayObject

@interface CircleArrayObject : RLMObject
@property RLM_GENERIC_ARRAY(CircleObject) *circles;
@end

#pragma mark CircleSetObject

@interface CircleSetObject : RLMObject
@property RLM_GENERIC_SET(CircleObject) *circles;
@end

#pragma mark ArrayPropertyObject

@interface ArrayPropertyObject : RLMObject

@property NSString *name;
@property RLM_GENERIC_ARRAY(StringObject) *array;
@property RLM_GENERIC_ARRAY(IntObject) *intArray;

@end

#pragma mark SetPropertyObject

@interface SetPropertyObject : RLMObject

@property NSString *name;
@property RLM_GENERIC_SET(StringObject) *set;
@property RLM_GENERIC_SET(IntObject) *intSet;

@end

#pragma mark DynamicObject

@interface DynamicTestObject : RLMObject

@property NSString *stringCol;
@property int intCol;

@end

#pragma mark AggregateObject

@interface AggregateObject : RLMObject

@property int     intCol;
@property float   floatCol;
@property double  doubleCol;
@property BOOL    boolCol;
@property NSDate *dateCol;

@end

RLM_COLLECTION_TYPE(AggregateObject)
@interface AggregateArrayObject : RLMObject
@property RLMArray<AggregateObject *><AggregateObject> *array;
@end

@interface AggregateSetObject : RLMObject
@property RLMSet<AggregateObject *><AggregateObject> *set;
@end

#pragma mark PrimaryStringObject

@interface PrimaryStringObject : RLMObject
@property NSString *stringCol;
@property int intCol;
@end

@interface PrimaryNullableStringObject : RLMObject
@property NSString *stringCol;
@property int intCol;
@end

@interface PrimaryIntObject : RLMObject
@property int intCol;
@end
RLM_COLLECTION_TYPE(PrimaryIntObject);

@interface PrimaryInt64Object : RLMObject
@property int64_t int64Col;
@end

@interface PrimaryNullableIntObject : RLMObject
@property NSNumber<RLMInt> *optIntCol;
@property int value;
@end

@interface ReadOnlyPropertyObject : RLMObject
@property (readonly) NSNumber *readOnlyUnsupportedProperty;
@property (readonly) int readOnlySupportedProperty;
@property (readonly) int readOnlyPropertyMadeReadWriteInClassExtension;
@end

#pragma mark IntegerArrayPropertyObject

@interface IntegerArrayPropertyObject : RLMObject

@property NSInteger number;
@property RLM_GENERIC_ARRAY(IntObject) *array;

@end

#pragma mark IntegerSetPropertyObject

@interface IntegerSetPropertyObject : RLMObject

@property NSInteger number;
@property RLM_GENERIC_SET(IntObject) *set;

@end

@interface NumberObject : RLMObject
@property NSNumber<RLMInt> *intObj;
@property NSNumber<RLMFloat> *floatObj;
@property NSNumber<RLMDouble> *doubleObj;
@property NSNumber<RLMBool> *boolObj;
@end

@interface NumberDefaultsObject : NumberObject
@end

@interface RequiredNumberObject : RLMObject
@property NSNumber<RLMInt> *intObj;
@property NSNumber<RLMFloat> *floatObj;
@property NSNumber<RLMDouble> *doubleObj;
@property NSNumber<RLMBool> *boolObj;
@end

#pragma mark CustomInitializerObject

@interface CustomInitializerObject : RLMObject
@property NSString *stringCol;
@end

#pragma mark AbstractObject

@interface AbstractObject : RLMObject
@end

#pragma mark PersonObject

@class PersonObject;
RLM_COLLECTION_TYPE(PersonObject);

@interface PersonObject : RLMObject
@property NSString *name;
@property NSInteger age;
@property RLMArray<PersonObject> *children;
@property (readonly) RLMLinkingObjects *parents;
@end

@interface PrimaryEmployeeObject : EmployeeObject
@end
RLM_COLLECTION_TYPE(PrimaryEmployeeObject);

@interface LinkToPrimaryEmployeeObject : RLMObject
@property PrimaryEmployeeObject *wrapped;
@end

@interface PrimaryCompanyObject : RLMObject
@property NSString *name;
@property RLM_GENERIC_ARRAY(PrimaryEmployeeObject) *employees;
@property RLM_GENERIC_SET(PrimaryEmployeeObject) *employeeSet;
@property PrimaryEmployeeObject *intern;
@property LinkToPrimaryEmployeeObject *wrappedIntern;
@end
RLM_COLLECTION_TYPE(PrimaryCompanyObject);

@interface ArrayOfPrimaryCompanies : RLMObject
@property RLM_GENERIC_ARRAY(PrimaryCompanyObject) *companies;
@end

@interface SetOfPrimaryCompanies : RLMObject
@property RLM_GENERIC_SET(PrimaryCompanyObject) *companies;
@end

#pragma mark ComputedPropertyNotExplicitlyIgnoredObject

@interface ComputedPropertyNotExplicitlyIgnoredObject : RLMObject
@property NSString *_URLBacking;
@property NSURL *URL;
@end

@interface RenamedProperties1 : RLMObject
@property (nonatomic) int propA;
@property (nonatomic) NSString *propB;
@property (readonly, nonatomic) RLMLinkingObjects *linking1;
@property (readonly, nonatomic) RLMLinkingObjects *linking2;
@end

@interface RenamedProperties2 : RLMObject
@property (nonatomic) int propC;
@property (nonatomic) NSString *propD;
@property (readonly, nonatomic) RLMLinkingObjects *linking1;
@property (readonly, nonatomic) RLMLinkingObjects *linking2;
@end

RLM_COLLECTION_TYPE(RenamedProperties1)
RLM_COLLECTION_TYPE(RenamedProperties2)

@interface LinkToRenamedProperties1 : RLMObject
@property (nonatomic) RenamedProperties1 *linkA;
@property (nonatomic) RenamedProperties2 *linkB;
@property (nonatomic) RLM_GENERIC_ARRAY(RenamedProperties1) *array;
@property (nonatomic) RLM_GENERIC_SET(RenamedProperties1) *set;
@end

@interface LinkToRenamedProperties2 : RLMObject
@property (nonatomic) RenamedProperties2 *linkC;
@property (nonatomic) RenamedProperties1 *linkD;
@property (nonatomic) RLM_GENERIC_ARRAY(RenamedProperties2) *array;
@property (nonatomic) RLM_GENERIC_SET(RenamedProperties2) *set;
@end

@interface RenamedPrimaryKey : RLMObject
@property (nonatomic) int pk;
@property (nonatomic) int value;
@end

#pragma mark FakeObject

@interface FakeObject : RLMObject
@end

@interface FakeEmbeddedObject : RLMEmbeddedObject
@end
