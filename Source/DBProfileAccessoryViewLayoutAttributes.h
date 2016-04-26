//
//  DBProfileAccessoryViewLayoutAttributes.h
//  DBProfileViewController
//
//  Created by Devon Boyer on 2016-04-15.
//  Copyright (c) 2015 Devon Boyer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  The `DBProfileAccessoryViewLayoutAttributes` object manages the layout-related attributes for an accessory view in a profile view controller.
 */
@interface DBProfileAccessoryViewLayoutAttributes : NSObject

/**
 *  Creates and returns a layout attributes object that represents the specified accessory view kind.
 *
 *  @param accessoryViewKind A string that identifies the type of the accessory view.
 *
 *  @return A new layout attributes object for the the specified accessory view kind.
 */
+ (instancetype)layoutAttributesForAccessoryViewOfKind:(NSString *)accessoryViewKind;

/**
 *  Initializes a layout attributes object that represents the specified accessory view kind.
 *
 *  @param accessoryViewKind A string that identifies the type of the accessory view.
 *
 *  @return A new layout attributes object for the the specified accessory view kind.
 */
- (instancetype)initWithAccessoryViewKind:(NSString *)accessoryViewKind;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  The accessory kind represented by the layout attributes.
 */
@property (nonatomic, copy, readonly) NSString *representedAccessoryKind;

/**
 *  The frame rectangle of the associated accessory view.
 */
@property (nonatomic) CGRect frame;

/**
 *  The bounds rectangle of the associated accessory view.
 */
@property (nonatomic) CGRect bounds;

/**
 *  Whether the accessory view is hidden of the associated accessory view.
 */
@property (nonatomic) BOOL hidden;

/**
 *  The size of the the associated accessory view's frame.
 */
@property (nonatomic) CGSize referenceSize;

/**
 *  The percent that the associated accessory view has transitioned within its visible bounds.
 */
@property (nonatomic) CGFloat percentTransitioned;

@property (nonatomic, nullable) NSLayoutConstraint *leadingConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *trailingConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *leftConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *rightConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *topConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *bottomConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *widthConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *heightConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *centerXConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *centerYConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *firstBaselineConstraint;
@property (nonatomic, nullable) NSLayoutConstraint *lastBaselineConstraint;

@end

NS_ASSUME_NONNULL_END