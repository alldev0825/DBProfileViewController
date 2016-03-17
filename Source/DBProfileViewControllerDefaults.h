//
//  DBProfileViewControllerDefaults.h
//  Pods
//
//  Created by Devon Boyer on 2016-03-16.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DBProfileViewController.h"
#import "DBProfilePictureView.h"

@interface DBProfileViewControllerDefaults : NSObject

+ (instancetype)sharedDefaults;

- (UIColor *)defaultSegmentedControlTintColor;

- (UIImage *)defaultBackBarButtonItemImageForTraitCollection:(UITraitCollection *)traitCollection;

- (DBProfileCoverPhotoOptions)defaultCoverPhotoOptions;

- (DBProfileCoverPhotoAnimationStyle)defaultCoverPhotoAnimationStyle;

- (CGFloat)defaultCoverPhotoHeightMultiplier;

- (DBProfilePictureAlignment)defaultProfilePictureAlignment;

- (DBProfilePictureSize)defaultProfilePictureSize;

- (DBProfilePictureStyle)defaultProfilePictureStyle;

- (UIEdgeInsets)defaultProfilePictureInsets;

- (CGFloat)defaultPullToRefreshTriggerDistance;

- (BOOL)defaultRememberIndexForSelectedContentController;

- (BOOL)defaultHidesSegmentedControlForSingleContentController;

- (BOOL)defaultCoverPhotoHidden;

- (BOOL)defaultCoverPhotoMimicsNavigationBar;

- (BOOL)defaultAllowsPullToRefresh;

@end
