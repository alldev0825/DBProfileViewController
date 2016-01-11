//
//  DBProfileDetailsView.m
//  Pods
//
//  Created by Devon Boyer on 2015-12-18.
//
//

#import "DBProfileDetailsView.h"

@implementation DBProfileDetailsView

#pragma mark - Initialization

- (instancetype)init {
    self = [super init];
    if (self) {
        [self _commonInit];
    }
    return self;
}

- (void)_commonInit {
    _nameLabel = [[UILabel alloc] init];
    _usernameLabel = [[UILabel alloc] init];
    _descriptionLabel = [[UILabel alloc] init];
    _editProfileButton = [[UIButton alloc] init];
    
    [self.nameLabel setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.usernameLabel setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.descriptionLabel setTranslatesAutoresizingMaskIntoConstraints:NO];
    [self.editProfileButton setTranslatesAutoresizingMaskIntoConstraints:NO];

    self.descriptionLabel.numberOfLines = 0;
    
    [self addSubview:self.nameLabel];
    [self addSubview:self.usernameLabel];
    [self addSubview:self.descriptionLabel];
    [self addSubview:self.editProfileButton];

    [self configureNameLabelLayoutConstraints];
    [self configureUsernameLabelLayoutConstraints];
    [self configureDescriptionLabelLayoutConstraints];
    [self configureEditProfileButtonLayoutConstraints];
    
    [self configureDefaultAppearance];
}

#pragma mark - Overrides

- (void)tintColorDidChange {
    [super tintColorDidChange];
    self.nameLabel.textColor = self.tintColor;
    self.usernameLabel.textColor = [self.tintColor colorWithAlphaComponent:0.54];
    self.descriptionLabel.textColor = [self.tintColor colorWithAlphaComponent:0.72];
}

#pragma mark - Defaults

- (void)configureDefaultAppearance {
    self.tintColor = [UIColor colorWithRed:33/255.0 green:37/255.0 blue:42/255.0 alpha:1];
    
    self.nameLabel.font = [UIFont boldSystemFontOfSize:20];
    self.usernameLabel.font = [UIFont systemFontOfSize:14];
    self.descriptionLabel.font = [UIFont systemFontOfSize:16];

    self.nameLabel.text = @"Devon Boyer";
    self.usernameLabel.text = @"@devboyer";
    self.descriptionLabel.text = @"CS @UWaterloo, iOS developer with a pasion for mobile computer and great #uidesign.";
    
    UIColor *editProfileButtonColor = [UIColor colorWithRed:135/255.0 green:153/255.0 blue:166/255.0 alpha:1];
    [self.editProfileButton setTitle:@"Edit profile" forState:UIControlStateNormal];
    [self.editProfileButton setTitleColor:editProfileButtonColor forState:UIControlStateNormal];
    self.editProfileButton.titleLabel.font = [UIFont boldSystemFontOfSize:14];
    self.editProfileButton.clipsToBounds = YES;
    self.editProfileButton.layer.cornerRadius = 6;
    self.editProfileButton.layer.borderWidth = 1;
    self.editProfileButton.layer.borderColor = editProfileButtonColor.CGColor;
}

#pragma mark - Auto Layout

- (void)configureNameLabelLayoutConstraints {
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.nameLabel attribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeTop multiplier:1 constant:54]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.nameLabel attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeLeft multiplier:1 constant:12]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.nameLabel attribute:NSLayoutAttributeRight relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeRight multiplier:1 constant:-12]];
}

- (void)configureUsernameLabelLayoutConstraints {
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.usernameLabel attribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:self.nameLabel attribute:NSLayoutAttributeBottom multiplier:1 constant:2]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.usernameLabel attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeLeft multiplier:1 constant:12]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.usernameLabel attribute:NSLayoutAttributeRight relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeRight multiplier:1 constant:-12]];
}

- (void)configureDescriptionLabelLayoutConstraints {
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.descriptionLabel attribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:self.usernameLabel attribute:NSLayoutAttributeBottom multiplier:1 constant:12]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.descriptionLabel attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeLeft multiplier:1 constant:12]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.descriptionLabel attribute:NSLayoutAttributeRight relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeRight multiplier:1 constant:-12]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.descriptionLabel attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeBottom multiplier:1 constant:-15]];
}

- (void)configureEditProfileButtonLayoutConstraints {
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.editProfileButton attribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeTop multiplier:1 constant:12]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.editProfileButton attribute:NSLayoutAttributeRight relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeRight multiplier:1 constant:-12]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.editProfileButton attribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1 constant:30]];
    [self addConstraint:[NSLayoutConstraint constraintWithItem:self.editProfileButton attribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:nil attribute:NSLayoutAttributeNotAnAttribute multiplier:1 constant:92]];
}

@end
