//
//  DWTagList.h
//
//  Created by Dominic Wroblewski on 07/07/2012.
//  Copyright (c) 2012 Terracoding LTD. All rights reserved.
//

#import <UIKit/UIKit.h>

//-------------------------------------------
/// Layout Types : How to layout tags in list
//-------------------------------------------

typedef enum {
    DWTagLayoutFlow,
    DWTagLayoutVertical,
    DWTagLayoutHorizontal,
    DWTagLayoutDefault = DWTagLayoutFlow
} DWTagLayout;

@class DWTagList, DWTagView;

@protocol DWTagListDelegate <NSObject>

@required

- (void)tagList:(DWTagList *) list selectedTag:(DWTagView *)tagView;

@end

@interface DWTagList : UIScrollView
{
    NSArray *textArray;
    CGSize sizeFit;
//    UIColor *lblBackgroundColor;
}

@property (nonatomic) BOOL viewOnly;
@property (nonatomic, strong) NSArray *textArray;
@property (nonatomic, weak) id<DWTagListDelegate> tagDelegate;
//@property (nonatomic, strong) UIColor *highlightedBackgroundColor;
@property (nonatomic) BOOL automaticResize;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, assign) CGFloat labelMargin;
@property (nonatomic, assign) CGFloat bottomMargin;
@property (nonatomic, assign) CGFloat horizontalPadding;
@property (nonatomic, assign) CGFloat verticalPadding;
@property (nonatomic, assign) CGFloat minimumWidth;

@property (nonatomic, strong) UIColor *defaultBackgroundColor;
@property (nonatomic, strong) UIColor *defaultTextColor;
@property (nonatomic, strong) UIColor *defaultTextShadowColor;
@property (nonatomic, assign) CGSize defaultTextShadowOffset;
@property (nonatomic, assign) CGFloat defaultCornerRadius;
@property (nonatomic, strong) UIColor *defaultBorderColor;
@property (nonatomic, assign) CGFloat defaultBorderWidth;


@property (nonatomic, assign) DWTagLayout layoutType;

//- (void)setTagBackgroundColor:(UIColor *)color;
//- (void)setTagHighlightColor:(UIColor *)color;

/// any properties starting with default* will not be applied autometically. Invoke this method to force.
-(void) applyDefaultTheme;

// add/set
- (void)setTags:(NSArray *)array;
- (void)addTag:(NSString *)tagText;

// find
-(DWTagView *) tagWithText:(NSString *) tagText;

// remove
- (void)removeTagWithText:(NSString *) tagText;
- (void)removeTag:(DWTagView *) tag;

- (void)display;
- (CGSize)fittedSize;

@end

@interface DWTagView : UIView

@property (nonatomic, readwrite) NSString *text;
@property (nonatomic, readwrite) UIColor *textColor;
@property (nonatomic, readwrite) UIColor *textShadowColor;
@property (nonatomic, readwrite) CGSize textShadowOffset;
@property (nonatomic, readwrite) CGFloat cornerRadius;
@property (nonatomic, readwrite) CGColorRef borderColor;
@property (nonatomic, readwrite) CGFloat borderWidth;

- (id) initForList:(DWTagList *) parentList;

@end
