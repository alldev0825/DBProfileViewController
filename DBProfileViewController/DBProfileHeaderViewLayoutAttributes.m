//
//  DBProfileHeaderViewLayoutAttributes.m
//  DBProfileViewController
//
//  Created by Devon Boyer on 2016-04-26.
//  Copyright (c) 2015 Devon Boyer. All rights reserved.
//

#import "DBProfileHeaderViewLayoutAttributes.h"
#import "DBProfileHeaderViewLayoutAttributes_Private.h"
#import "DBProfileAccessoryViewLayoutAttributes_Private.h"
#import "DBProfileViewController.h"

@implementation DBProfileHeaderViewLayoutAttributes

+ (NSArray<NSString *> *)keyPathsForBindings
{
    return @[NSStringFromSelector(@selector(headerStyle)),
             NSStringFromSelector(@selector(scrollEffects))];
}

+ (instancetype)layoutAttributes
{
    return [super layoutAttributesForAccessoryViewOfKind:DBProfileAccessoryKindHeader];
}

- (instancetype)initWithAccessoryViewKind:(NSString *)accessoryViewKind
{
    self = [super initWithAccessoryViewKind:accessoryViewKind];
    if (self) {
        self.headerStyle = DBProfileHeaderStyleNavigation;
        self.scrollEffects = DBProfileHeaderScrollEffectStretch;
    }
    return self;
}

- (void)uninstallConstraints {
    [super uninstallConstraints];
    self.navigationConstraint = nil;
    self.topLayoutGuideConstraint = nil;
    self.topSuperviewConstraint = nil;
}

#pragma mark - NSObject

- (BOOL)isEqual:(id)object {
    if (![object isKindOfClass:[self class]]) return NO;
    if (![super isEqual:object]) return NO;
    DBProfileHeaderViewLayoutAttributes *otherObject = (DBProfileHeaderViewLayoutAttributes *)object;
    return self.headerStyle == otherObject.headerStyle && self.scrollEffects == otherObject.scrollEffects;
}

#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone
{
    DBProfileHeaderViewLayoutAttributes *copy = [super copyWithZone:zone];
    
    copy.headerStyle = self.headerStyle;
    copy.scrollEffects = self.scrollEffects;
    copy.navigationConstraint = self.navigationConstraint;
    copy.topLayoutGuideConstraint = self.topLayoutGuideConstraint;
    copy.topSuperviewConstraint = self.topSuperviewConstraint;

    return copy;
}

@end
