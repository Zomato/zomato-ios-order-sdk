//
//  ZOnlineOrderManager.h
//  ZO2Kit
//
//  Created by Gamandeep Sethi on 28/08/15.
//  Copyright (c) 2015 Zomato Media Pvt. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "PlaceOrderTab.h"
#import "AccountBannerObject.h"

typedef NS_ENUM(NSInteger, ZomatoTrackingEventType) {
    ZomatoTrackingEventTypePageView,
    ZomatoTrackingEventTypeClickStream
};

/**
 *  this notification is fired when any of the order in active orders array is changed, listen to this to fetch active orders array
 */
extern NSString *const zActiveOrdersArrayChanged;

/**
 *  this notification is fired when status of any order is changed like it becomes on the way or delivered, in the object of the notification, zomatoorder type object is returned
 */
extern NSString *const zOrderStatusChanged;

/**
 *  this notification is fired when the order is placed, in the object of the notification, zomatoorder type object is returned
 */
extern NSString *const zOrderPlaced;


@protocol ZOnlineOrderManagerDelegate <NSObject>

/**
 *  this will be called whenever user taps on the right action bar button in the navigation bar present on the home restaurant search page. (Conform to ZOnlineOrderManagerDelegate protocol and call `setDelegate:` with the `sharedInitializer` object)
 */
@optional
- (void)didTapHomeRightActionBarButtonOnNavigationContoller:(UINavigationController *)navigationController;

/**
 *  this will be called whenever the user dismisses the session for ordering. The `isOrderPlaced` BOOL flag tells whether the order was placed in the current session.
 */
@optional
- (void)didDismissZomatoOrderFlowWithOrderPlaced:(BOOL)isOrderPlaced;


/**
 *  this will be called whenever the user verifies the phone number. The phone number can be stored at your end and can be passed next time.
 */
@optional
- (void)userSuccessfullyVerifiedPhoneNumber:(NSString *)phoneNumber;

/**
 * this method can be used to register and track events.
 */
@optional
- (void)trackZomatoEvent:(NSString *)eventName trackingEventType:(ZomatoTrackingEventType)eventType data:(NSDictionary *)dataDict;

@end

@interface ZOnlineOrderManager : NSObject

/**
 *  Get shared initializer
 *
 *  @return shared initializer
 */
+ (ZOnlineOrderManager *)sharedInitializer;

/**
 *  Use this function to initialize zomato online ordering manager, this function has to be called before calling any function in this kit
 *
 *  @param key    api key provided to you
 *  @param secret api secret provided to you
 */
+ (void)setAPIKey:(NSString*)key andAPISecret:(NSString*)secret;

/**
 *   For font customization set your fon't name for font type "regular", "medium", "bold", "thin".
 *   This is optional. By default we are using HelveticaNeue family
 *
 *  @param fontName e.g. "ProximaNova-Bold"
 */
+ (void)setFontRegularName:(NSString *)fontName;
+ (void)setFontMediumName:(NSString *)fontName;
+ (void)setFontBoldName:(NSString *)fontName;
+ (void)setFontThinName:(NSString *)fontName;


/**
 *  Use this to set a delegate conforming to the ZOnlineOrderManagerDelegate protocol.
 */

@property (nonatomic, weak) id<ZOnlineOrderManagerDelegate> delegate;

/**
 *  Use this to set a first banner on home page. If you are settings the first banner then 
 *  imageUrl, title, deeplinkUrl, and tagline are REQUIRED properties that needs to be set.
 */

@property (nonatomic, strong) AccountBannerObject *homePageBannerObject;


/**
 *  Use this to set banner on final page. If you are settings the first banner then
 *  imageUrl, title, and subtitle are REQUIRED properties that needs to be set.
 */

@property (nonatomic, strong) AccountBannerObject *finalPaymentPageBannerObject;


/**
 *  Use this to set initial search string if required. Default is nil.
 */

@property (nonatomic, strong) NSString *initialSearchString;


/**
 *  Use this to set initial search params  dictionary if required. Default is nil.
 */

@property (nonatomic, strong) NSDictionary *initialSearchParams;


/**
 *  Use this to add space below title text 'Menu' on Menu Page. Required in some font family. Default is nil.
 */

@property (nonatomic, strong) NSNumber *menuPageHeaderSpace;

/**
 *  Use this to add/remove space above checkbox and radio button in customization of an item
 */

@property (nonatomic, strong) NSNumber *customizationSelectionItemEmptySpace;


/**
 *  Call this function to present the online ordering view controller to present
 *
 *  @param number     Phone number of the user
 *  @param controller View controller on which you want to present online ordering view controller
 */
- (void)startOnlineOrderWithPhoneNumber:(NSString *)number viewController:(UIViewController *)controller;


/**
 *  Call this function to push the online ordering view controller to present
 *
 *  @param number     Phone number of the user
 *  @param controller UINavigation Controller on which you want to push online ordering view controller
 */
- (void)startOnlineOrderWithPhoneNumber:(NSString *)number pushOnNavViewController:(UINavigationController *)controller;


/**
 *  Call this function to present the order detail page
 *
 *  @param orderId      Order id for which zomato order object is needed
 *  @param controller   View controller on which you want to present online ordering view controller
 */
- (void)showOrderDetailViewControllerForOrderID:(NSString *)orderId viewController:(UIViewController *)controller;

/**
 *  Call this function to fetch all the active orders array, an order is considered to be active if it is not rejected, delivered or timed out
 *
 *  @param completionHandler this block gets called, when the data is retrieved
 */
- (void)getActiveOrdersArrayWithCompletionHandler:(void (^)(NSError *error, NSArray *activeOrdersArray))completionHandler;

/**
 *  This is used to retrieve the PlaceOrderTab object given the order id
 *
 *  @param orderId           order id for which zomato order object is needed
 *  @param completionHandler this block gets called when data is retrieved
 */
- (void)getZomatoOrderObjectWithOrderId:(NSString *)orderId completionHandler:(void (^)(NSError *error, PlaceOrderTab *zomatoOrderObject))completionHandler;

/**
 *  Call this function to set user Location for showing restaurant suggestions
 *  @param userLocation   CLLocation object of user location
 */
- (void)setUserLocation:(CLLocation *)userLocation;

/**
 *  Use this method to set the name of the User for ordering.
 *
 *  @param fullName Name of the User
 */
- (void)setUserFullName:(NSString *)fullName;


/**
 *  Use this method to set the phone of the User for ordering.
 *
 *  @param Phone Number of the User
 */
- (void)setUserPhoneNumber:(NSString *)number;

/**
 *  Call invalidate if user logs out from your app. Show that we can clear logged in user data.
 */
+ (void)invalidate;


/**
 *  Call this function if you want to change the appearance of Navigation Bar. Default Value: NO
 *  Default Appearance: Background Color: WHITE; Text Color: BLACK; Back Button Color: THEME COLOR
 *  Custom  Appearance: Background Color: THEME COLOR; Text Color: WHITE; Back Button Color: WHITE
 *  @param value   BOOL to switch between default and custom appearnace
 */
+ (void)shouldSetNavigationBarAppearanceToDefault:(BOOL)value;

/**
 *  Call this function to set ZomatoUserToken so that user's saved addresses and data mapped to zomato user token is set in the app
 *
 *  @param zomatoUserToken   NSString
 */
- (void)setZomatoUserToken:(NSString *)zomatoUserToken;


/**
 *  This is used to retrieve zomato user token
 *
 *  @param completionHandler this block gets called when data is retrieved
 */
- (void)getZomatoUserTokenWithCompletionHandler:(void (^)(NSError *error, NSString *zomatoUserToken))completionHandler;

/**
 *  Call this function to set Theme Color. Default Color: 0xcb202d
 *
 *  @param colorValue   Color Value
 */
+ (void)setThemeColor:(NSInteger)colorValue;

/**
 *  Call this function to set Bottom Bar Background Color. Default Color: 0x099e44
 *
 *  @param colorValue   Color Value
 */
+ (void)setBottomBarColor:(NSInteger)colorValue;


/**
 *
 *  Set this to yes if you are using to have dark theme. Default value is NO
 *
 *  @param BOOL value
 */


+ (void)setIsThemeDark:(BOOL)value;


// Call given below functions to set font size of different custom labels

/**
 *  Home Label used in Showcase  Default Value: 22
 */
+ (void)setFontHomeLabel:(NSInteger)fontHomeLabel;


/**
 *  Home SubLabel used in Showcase  Default Value: 15
 */
+ (void)setFontHomeSublabel:(NSInteger)fontHomeSublabel;


/**
 * Header View font. Already set. To be used for header views only. Default Value: 20
 */
+ (void)setFontNavBarLabel:(NSInteger)fontNavBarLabel;


/**
 * To be used for as the standard font for Primary Single Line labels. E.g. Restaurant name in res snippet, User name in user snippet. Default Value: 17
 */
+ (void)setFontPrimaryLabel:(NSInteger)fontPrimaryLabel;


/**
 * To be used for as the standard font for Primary Single Line labels. E.g. Restaurant name in res snippet, User name in user snippet. Default Value: 17
 */
+ (void)setFontAlternatePrimaryLabel:(NSInteger)fontAlternatePrimaryLabel;


/**
 * To be used for Title of menu items. Mostly used in TableViewCells. For e.g. Photos, reviews, menus. Default Value: 19
 */
+ (void)setFontTitletextLabel:(NSInteger)fontTitletextLabel;


/**
 * To be used for subtext accompanying a Title or a Primary label. Eg. When location is displayed under a restaurant name. Default Value: 12
 */
+ (void)setFontSubtextLabel:(NSInteger)fontSubtextLabel;


/**
 * To be used for all the body text. E.g. Review text, restaurant info  Default Value: 16
 */
+ (void)setFontBodyLabel:(NSInteger)fontBodyLabel;


/**
 * To be used for all the body text. E.g. Review text, restaurant info  Default Value: 15
 */
+ (void)setFontBodyLabelBold:(NSInteger)fontBodyLabelBold;


/**
 * To be used while displaying the rating of a restaurant. Default Value: 14
 */
+ (void)setFontRatingLabel:(NSInteger)fontRatingLabel;


/**
 * To be used while displaying the rating of a restaurant. Default Value: 11
 */
+ (void)setFontRatingLabelSmall:(NSInteger)fontRatingLabelSmall;


/**
 * To be used while displaying the rating of a restaurant. Default Value: 15
 */
+ (void)setFontRatingLabelMedium:(NSInteger)fontRatingLabelMedium;


/**
 * To be used for diplaying tags. eg. "open now" Default Value: 8
 */
+ (void)setFontTagLabel:(NSInteger)fontTagLabel;


/**
 * To be used for page headings(not in nav bar). Eg. Hello Udit on home page. Default Value: 30
 */
+ (void)setFontHeroLabel:(NSInteger)fontHeroLabel;


/**
 * To be used for labels on an overlay. E.g. Phone Number picker. Default Value: 24
 */
+ (void)setFontOverlayLabel:(NSInteger)fontOverlayLabel;


/**
 * To be used for a very small sized subtext. E.g. subtext under the facebook login button. Default Value: 13
 */
+ (void)setFontTinyLabel:(NSInteger)fontTinyLabel;


/**
 * To be used for a very small sized subtext. E.g. subtext under the facebook login button. Default Value: 13
 */
+ (void)setFontTinyLabelBold:(NSInteger)fontTinyLabelBold;


/**
 * To be used for a for search info strings. Default Value: 14
 */
+ (void)setFontSearchInfoLabel:(NSInteger)fontSearchInfoLabel;

/**
 * Font to be used in Table section headers. Default Value: 14
 */
+ (void)setFontSectionHeaderLabel:(NSInteger)fontSectionHeaderLabel;


/**
 * Font to be used as an alter to Table section headers.  Default Value: 12
 */
+ (void)setFontSectionHeaderAlternateLabel:(NSInteger)fontSectionHeaderAlternateLabel;


/**
 *  Font to be used for big dark labels  Default Value: 14
 */
+ (void)setFontWeekBadgeLabel:(NSInteger)fontWeekBadgeLabel;


/**
 *  Font to be used for price labels  Default Value: 14
 */
+ (void)setFontPriceLabel:(NSInteger)fontPriceLabel;


/**
 * Font to be used in Info headers.  Default Value: 12
 */
+ (void)setFontInfoHeaderLabel:(NSInteger)fontInfoHeaderLabel;


/**
 * Font to be used for tagged users.  Default Value: 15
 */
+ (void)setFontTaggedUser:(NSInteger)fontTaggedUser;


/**
 * Font to be used for Small Headings Label.  Default Value: 10
 */
+ (void)setFontSmallHeadingsLabel:(NSInteger)fontSmallHeadingsLabel;



/**
 * Font to be used for order checkout flow button  Default Value: 20
 */
+ (void)setFontSubmitButton:(NSInteger)fontSubmitButton;




// Call given below functions to set text color of different custom labels


/**
 *  Home Label used in Showcase  Default Value: 0x000000
 */
+ (void)setColorHomeLabel:(NSInteger)colorHomeLabel;


/**
 *  Home SubLabel used in Showcase  Default Value: 0x9d9d9d
 */
+ (void)setColorHomeSublabel:(NSInteger)colorHomeSublabel;


/**
 * To be used for as the standard font for Primary Single Line labels. E.g. Restaurant name in res snippet, User name in user snippet. Default Value: 0x000000
 */
+ (void)setColorPrimaryLabel:(NSInteger)colorPrimaryLabel;


/**
 * To be used for Title of menu items. Mostly used in TableViewCells. For e.g. Photos, reviews, menus. Default Value: 0x000000
 */
+ (void)setColorTitletextLabel:(NSInteger)colorTitletextLabel;


/**
 * To be used for subtext accompanying a Title or a Primary label. Eg. When location is displayed under a restaurant name. Default Value: 0x9d9d9d
 */
+ (void)setColorSubtextLabel:(NSInteger)colorSubtextLabel;


/**
 * To be used for all the body text. E.g. Review text, restaurant info  Default Value: 0x2d2d2a
 */
+ (void)setColorBodyLabel:(NSInteger)colorBodyLabel;


/**
 * Header View font. Already set. To be used for header views only. Default Value: 0x000000
 */
+ (void)setColorNavBarLabel:(NSInteger)colorNavBarLabel;


/**
 * To be used for page headings(not in nav bar). Eg. Hello Udit on home page. Default Value: 0x000000
 */
+ (void)setColorHeroLabel:(NSInteger)colorHeroLabel;


/**
 * To be used for labels on an overlay. E.g. Phone Number picker. Default Value: 0x9d9d9d
 */
+ (void)setColorOverlayLabel:(NSInteger)colorOverlayLabel;


/**
 * Font to be used in Table section headers. Default Value: 0x9d9d9d
 */
+ (void)setColorSectionHeaderLabel:(NSInteger)colorSectionHeaderLabel;


/**
 * Font to be used as an alter to Table section headers.  Default Value: 0x9d9d9d
 */
+ (void)setColorSectionHeaderLabelAlternate:(NSInteger)colorSectionHeaderLabelAlternate;


/**
 * Font to be used in Info headers.  Default Value: 0x9d9d9d
 */
+ (void)setColorInfoHeaderLabel:(NSInteger)colorInfoHeaderLabel;


/**
 * To be used for a very small sized subtext. E.g. subtext under the facebook login button. Default Value: 0x9d9d9d
 */
+ (void)setColorTinyLabel:(NSInteger)colorTinyLabel;


/**
 * To be used for all the underline text  Default Value: 0x000000
 */
+ (void)setColorUnderlineLabel:(NSInteger)colorUnderlineLabel;


/**
 * To be used for rounded icon color. Default Value: 0xFFFFFF
 */
+ (void)setColorIconFgRoundedLabel:(NSInteger)colorIconFgRoundedLabel;


/**
 * To be used for rounded icon background color. Default Value: 0x099e44
 */
+ (void)setColorIconBgRoundedLabel:(NSInteger)colorIconBgRoundedLabel;


/**
 *  Font to be used for price labels  Default Value: 0x6D6D6D
 */
+ (void)setColorPriceLabel:(NSInteger)colorPriceLabel;


/**
 * Font to be used for tagged users.  Default Value: 0x9d9d9d
 */
+ (void)setColorTaggedUser:(NSInteger)colorTaggedUser;


/**
 * To be used for search info strings. Default Value: 0x9d9d9d
 */
+ (void)setColorSearchInfoLabel:(NSInteger)colorSearchInfoLabel;

/**
 * To be used for backgroundColor. Default Value: 0xFFFFFF
 */

+ (void) setBackgroundColor:(NSInteger)colorBg;

/**
 * To be used for darkBackgroundColor. Default Value: 0x9d9d9d
 */

+ (void) setDarkBackgroundColor:(NSInteger)colorDarkBg;

/**
 *
 * Set image for the right navigation bar button on Ordering Home
 *
 *  @param image UIImage object for the button image. The button is 54x54 points in size.
 */
+ (void)setRightActionButtonImage:(UIImage *)image;

/**
 *
 *  On setting value to YES, it will dismiss order flow after placing an order
 *
 *  @param value : BOOL  Default Value:YES
 */
+ (void)shouldDismissOrderFlowAfterPlacingOrder:(BOOL)value;

/**
 *
 *  Set the restaurant id before starting the order flow to open a particular restaurant
 *
 *  @param value : (NSNumber *) id of a restaurant
 */
- (void)setRestaurantId:(NSNumber *)resId;

/**
 *
 *  Set the address of the user before starting the order flow
 *
 *  @param value : (NSString *) address of the user
 */
- (void)setUserAddress:(NSString *)userAddress;

@end