//
//  DBProfileViewController.h
//  DBProfileViewController
//
//  Created by Devon Boyer on 2015-12-18.
//  Copyright (c) 2015 Devon Boyer. All rights reserved.
//
//  Released under an MIT license: http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

#import "DBProfileContentPresenting.h"
#import "DBProfileViewControllerDelegate.h"
#import "DBProfileViewControllerDataSource.h"
#import "DBProfileViewControllerConstants.h"

@class DBProfileViewController;
@class DBProfileCoverPhotoView;
@class DBProfileAccessoryView;

NS_ASSUME_NONNULL_BEGIN

/*!
 @class DBProfileViewController
 @abstract The `DBProfileViewController` class is a view controller that is specialized to display a profile interface.
 @discussion This class manages and displays a collection of content controllers and customizable subviews associated with a profile interface.
 */
@interface DBProfileViewController : UIViewController

///---------------------------------------------
/// @name Creating Profile View Controllers
///---------------------------------------------

/*!
 @abstract Initializes a newly created profile view controller.
 @param segmentedControlClass Specify the custom UISegmentedControl subclass you want to use, or specify nil to use the standard UISegmentedControl class.
*/
- (instancetype)initWithSegmentedControlClass:(nullable Class)segmentedControlClass;

/*!
 @abstract Initializes a newly created profile view controller.
 @param segmentedControlClass Specify the custom UISegmentedControl subclass you want to use, or specify nil to use the standard UISegmentedControl class.
 @param avatarViewClass Specify the custom DBProfileAccessoryView subclass you want to use, or specify nil to use the standard DBProfileAvatarView class.
 */
- (instancetype)initWithSegmentedControlClass:(nullable Class)segmentedControlClass avatarViewClass:(nullable Class)avatarViewClass;

/*!
 @abstract The object that acts as the view controller's delegate.
 */
@property (nonatomic, weak, nullable) id<DBProfileViewControllerDelegate> delegate;

/*!
 @abstract The object that acts as the view controller's data source.
 */
@property (nonatomic, weak, nullable) id<DBProfileViewControllerDataSource> dataSource;

/*!
 @abstract A view that is displayed under the cover photo and above the content controllers.
 @discussion The default is an instance of `DBProfileDetailsView`.
 @warning The `detailsView` cannot be nil.
 */
@property (nonatomic, strong) UIView *detailsView;

/*!
 @abstract The navigation item used to represent the profile view controller's navigation item when using `coverPhotoMimicsNavigationBar`
 */
@property (nonatomic, strong, readonly) UINavigationItem *coverPhotoMimicsNavigationBarNavigationItem;

///---------------------------------------------
/// @name Reloading the Profile View Controller
///---------------------------------------------

/*!
 @abstract Begins a series of method calls that modify height calculations for subviews of the profile view controller.
 @discussion Call this method if you want subsequent height changes to subviews to be animated simultaneously. 
 @warning This group of methods must conclude with an invocation of endUpdates. You should not call reloadData within the group.
 */
- (void)beginUpdates;

/*!
 @abstract Concludes a series of method calls that modify height calculations for subviews of the profile view controller.
 @discussion You call this method to bracket a series of method calls that begins with beginUpdates. When you call endUpdates, height changes to subviews are animated simultaneously.
 */
- (void)endUpdates;

/*!
 @abstract Reloads the content controllers of the profile view controller by rebuilding the view heirarchy.
 */
- (void)reloadData;

///---------------------------------------------
/// @name Configuring Segmented Control
///---------------------------------------------

/*!
 @abstract The segmented control managed by the profile view controller.
 */
@property (nonatomic, assign, readonly) UISegmentedControl *segmentedControl;

/*!
 @abstract YES if the segmented control is hidden when there is only one content controller, NO otherwise.
 @discussion The default is YES
 */
@property (nonatomic, assign) BOOL hidesSegmentedControlForSingleContentController;

///---------------------------------------------
/// @name Managing Selections
///---------------------------------------------

/*!
 @abstract The index of the selected content controller.
 */
@property (nonatomic, assign, readonly) NSUInteger indexForSelectedContentController;

/*!
 @abstract Selects a content controller in the profile view controller at the specified index.
 @param index An index identifying a content controller in the profile view controller.
 */
- (void)selectContentControllerAtIndex:(NSInteger)index;

/*!
 @abstract Selects the accessory view.
 @param animated YES if setting selecting the accessory view should be animated, NO otherwise.
 */
- (void)selectAccessoryView:(DBProfileAccessoryView *)accessoryView animated:(BOOL)animated;

/*!
 @abstract Deselects the accessory view.
 @param animated YES if setting deselecting the accessory view should be animated, NO otherwise.
 */
- (void)deselectAccessoryView:(DBProfileAccessoryView *)accessoryView animated:(BOOL)animated;

///---------------------------------------------
/// @name Configuring Cover Photo View
///---------------------------------------------

/*!
 @abstract An accessory view that is displays a cover photo.
 */
@property (nonatomic, strong, readonly) DBProfileCoverPhotoView *coverPhotoView;

/*!
 @abstract Specifies the height of the cover photo relative to the height of the screen.
 @discussion The default is 0.18. To hide the cover photo set `coverPhotoHidden` to YES. When using `coverPhotoMimicsNavigationBar` is important that this value results in the height of the cover photo being greater than the height of a navigation bar.
 @warning `coverPhotoHeightMultiplier` must be greater than 0 or less than or equal to 1.
 */
@property (nonatomic, assign) CGFloat coverPhotoHeightMultiplier;

/*!
 @abstract YES if the cover photo should be hidden, NO otherwise.
 @discussion The default is `NO`.
 */
@property (nonatomic, assign) BOOL coverPhotoHidden;

/*!
 @abstract The options that specify the behaviour of the covere photo.
 @discussion The default is `DBProfileCoverPhotoOptionStretch`.
 */
@property (nonatomic, assign) DBProfileCoverPhotoOptions coverPhotoOptions;

/*!
 @abstract YES if the cover photo should mimic a navigation bar when the view is scrolled, NO otherwise.
 @discussion The default is YES. When this property is set to YES you should set `automaticallyAdjustsScrollViewInsets` to NO, otherwise set `automaticallyAdjustsScrollViewInsets` to YES.
 */
@property (nonatomic, assign) BOOL coverPhotoMimicsNavigationBar;

///---------------------------------------------
/// @name Configuring Avatar View
///---------------------------------------------

/*!
 @abstract An accessory view that is displays an avatar image.
 */
@property (nonatomic, strong, readonly) DBProfileAccessoryView *avatarView;

/*!
 @abstract Specifies the alignment for the avatar.
 @discussion The default is `DBProfileAvatarAlignmentLeft`.
 */
@property (nonatomic, assign) DBProfileAvatarAlignment avatarAlignment;

/*!
 @abstract Specifies the size for the avatar.
 @discussion The default is `DBProfileAvatarSizeNormal`.
 */
@property (nonatomic, assign) DBProfileAvatarSize avatarSize;

/*!
 @abstract The distance that the avatar view is inset from the `avatarAlignment`.
 */
@property (nonatomic, assign) UIEdgeInsets avatarInset;

///----------------------------------------------
/// @name Configuring Pull-To-Refresh
///----------------------------------------------

/*!
 @abstract YES if the pull-to-refresh indicator is currently animating, NO otherwise.
 */
@property (nonatomic, assign, readonly, getter=isRefreshing) BOOL refreshing;

/*!
 @abstract YES to enable pull-to-refresh, NO otherwise.
 @discussion The default is YES.
 */
@property (nonatomic, assign) BOOL allowsPullToRefresh;

/*!
 @abstract Hides the pull-to-refresh indicator if it is currently animating.
 */
- (void)endRefreshing;

@end

@interface DBProfileViewController (Deprecated)

- (void)setCoverPhotoImage:(UIImage *)image animated:(BOOL)animated __deprecated;
- (void)setAvatarImage:(UIImage *)avatarImage animated:(BOOL)animated __deprecated;

@end

NS_ASSUME_NONNULL_END
