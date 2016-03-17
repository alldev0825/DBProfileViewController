//
//  DBProfileCoverPhotoView.h
//  DBProfileViewController
//
//  Created by Devon Boyer on 2016-01-08.
//  Copyright (c) 2015 Devon Boyer. All rights reserved.
//
//  Released under an MIT license: http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class DBProfileCoverPhotoView;

@protocol DBProfileCoverPhotoViewDelegate <NSObject>

- (void)coverPhotoViewDidHighlight:(DBProfileCoverPhotoView *)coverPhotoView;
- (void)coverPhotoViewDidUnhighlight:(DBProfileCoverPhotoView *)coverPhotoView;

@end

/*!
 @class DBProfileCoverPhotoView
 @abstract The `DBProfileCoverPhotoView` class displays a cover photo.
 */
@interface DBProfileCoverPhotoView : UIView

@property (nonatomic, weak) id<DBProfileCoverPhotoViewDelegate> delegate;

/*!
 @abstract The image view that displays the cover photo.
 */
@property (nonatomic, strong, readonly) UIImageView *imageView;

/*!
 @abstract The image view that overlays the cover photo.
 */
@property (nonatomic, strong, readonly) UIImageView *overlayImageView;

/*!
 @abstract A gradient view that overlays the cover photo to allow for visibility of any overlayed subviews.
 */
@property (nonatomic, strong, readonly) UIView *overlayView;


@property (nonatomic, assign, getter=isHighlighted) BOOL highlighted;

- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
