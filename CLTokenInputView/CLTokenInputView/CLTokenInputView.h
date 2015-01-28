//
//  CLTokenInputView.h
//  CLTokenInputView
//
//  Created by Rizwan Sattar on 2/24/14.
//  Copyright (c) 2014 Cluster Labs, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "CLToken.h"

@class CLTokenInputView;
@protocol CLTokenInputViewDelegate <NSObject>

@optional
- (void)tokenInputView:(CLTokenInputView *)view didChangeText:(NSString *)text;
- (void)tokenInputView:(CLTokenInputView *)view didAddToken:(CLToken *)token;
- (void)tokenInputView:(CLTokenInputView *)view didRemoveToken:(CLToken *)token;
/** 
 * Called when the user attempts to press the Return key with text partially typed.
 * @return A CLToken for a match (typically the first item in the matching results),
 * or nil if the text shouldn't be accepted.
 */
- (CLToken *)tokenInputView:(CLTokenInputView *)view tokenForText:(NSString *)text;
- (void)tokenInputView:(CLTokenInputView *)view didChangeHeightTo:(CGFloat)height;

@end

@interface CLTokenInputView : UIView

@property (weak, nonatomic) IBOutlet NSObject <CLTokenInputViewDelegate> *delegate;
/** An optional view that shows up presumably on the first line */
@property (strong, nonatomic) UIView *fieldView;
/** Option text which can be displayed before the first line (e.g. "To:") */
@property (copy, nonatomic) IBInspectable NSString *fieldName;
@property (copy, nonatomic) IBInspectable NSString *placeholderText;
@property (strong, nonatomic) UIView *accessoryView;
@property (assign, nonatomic) IBInspectable UIKeyboardType keyboardType;
@property (assign, nonatomic) IBInspectable UITextAutocapitalizationType autocapitalizationType;
@property (assign, nonatomic) IBInspectable UITextAutocorrectionType autocorrectionType;
@property (assign, nonatomic) IBInspectable BOOL drawBottomBorder;

@property (readonly, nonatomic) NSArray *allTokens;
@property (readonly, nonatomic, getter = isEditing) BOOL editing;
@property (readonly, nonatomic) CGFloat textFieldDisplayOffset;
@property (readonly, nonatomic) NSString *text;

- (void)addToken:(CLToken *)token;
- (void)removeToken:(CLToken *)token;
- (CLToken *)tokenizeTextfieldText;

// Editing
- (void)beginEditing;
- (void)endEditing;

@end
