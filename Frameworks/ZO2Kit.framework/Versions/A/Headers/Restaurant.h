//
//  Restaurant.h
//  RestKitUtilityAndTest
//
//  Created by Arup Saha on 17/05/12.
//  Copyright (c) 2012 Zomato Media Pvt. Ltd. All rights reserved.
//

#import "ZomatoObject.h"
#import "Location.h"
#import "Promo.h"


typedef enum {
    RestaurantRequestTypeInfo = 0,
    RestaurantRequestTypeMenus = 1,
    RestaurantRequestTypePhotos = 2,
    RestaurantRequestTypeReviews = 3
} RestaurantRequestType;

@class RestaurantDeliveryInfo;

@interface Restaurant : ZomatoObject

@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) Location* location;
@property (nonatomic, strong) NSString* mobilePhone;
@property (nonatomic,strong)  NSString* restaurantDescription;
@property (nonatomic, strong) NSString* dishes;
@property (nonatomic, strong) NSString* cuisines;
@property (nonatomic, strong) NSNumber* hasCitibankDiscount;
@property (nonatomic, strong) NSNumber* hasEmiratesDiscount;
@property (nonatomic, strong) NSString* citibankDiscountDetail;
@property (nonatomic, strong) NSString* emiratesDiscountDetail;
@property (nonatomic, strong) NSString* timings;
@property (nonatomic, strong) NSMutableArray *allTimings;
@property (nonatomic, strong) NSMutableString* cftAlcoholText;
@property (nonatomic, strong) NSString* featuredImage;
@property (nonatomic, strong) NSString* bannerImage;
@property (nonatomic, strong) NSString* whiteLabelBannerIcon;
@property (nonatomic, strong) NSString* featuredImageForIphone4;
@property (nonatomic, strong) NSNumber* avgCostForTwo;
@property (nonatomic, strong) NSNumber* priceRange;
@property (nonatomic, strong) NSNumber *hasMenu;
@property (nonatomic,) int hasBar;
@property (nonatomic) int hasAC;
@property (nonatomic) int hasWifi;
@property (nonatomic) int hasTakeAway;
@property (nonatomic) int isPureVeg;
@property (nonatomic) int servesVeg;
@property (nonatomic) int isSportsBar;
@property (nonatomic) int servesNonVeg;
@property (nonatomic) int acceptsMealCoupons;
@property (nonatomic) int hasSmokingArea;
@property (nonatomic) int hasOutdoorSeating;
@property (nonatomic, strong) NSNumber *acceptsCreditCard;
@property (nonatomic) int hasDineIn;
@property (nonatomic) int hasCoordinates;
@property (nonatomic, strong) NSString *mobileDisplay;
@property (nonatomic) int hasLiveMusic;
@property (nonatomic) int hasNightLife;
@property (nonatomic) int serviceCharge;
@property (nonatomic) int vat;
@property (nonatomic, strong) NSString* buffet_details;
@property (nonatomic, strong) NSString *brunch_title;
@property (nonatomic, strong) NSString *brunch_description;
@property (nonatomic, strong) NSNumber *brunch_start_time;
@property (nonatomic, strong) NSNumber *brunch_end_time;
@property (nonatomic, strong) NSString* reservationTxt;
@property (nonatomic) int stagEntryFlag;
@property (nonatomic) int hasSheesha;
@property (nonatomic, strong) NSNumber* cost_of_beer;
@property (nonatomic, strong) NSString* happy_hour_details;
@property (nonatomic, strong) NSString* entry_fee;
@property (nonatomic, strong) NSNumber* userRating;
@property (nonatomic, strong) NSString* ratingText;
@property (nonatomic, strong) NSMutableArray* userPhotos;
@property (nonatomic, strong) NSString* photoUrl;
@property (nonatomic, strong) NSMutableArray* menus;
@property (nonatomic, strong) NSString* menuUrl;
@property (nonatomic, weak) NSString* facilitiesString;
@property (nonatomic, weak) NSString* noFacilitiesString;
@property (nonatomic, strong) NSMutableArray* userReviews;
@property (nonatomic, strong) NSMutableArray* my_review;
@property (nonatomic, strong) NSMutableArray* recommendations;
@property (nonatomic, strong) NSString *isUserFavorite;
@property (nonatomic, strong) NSString *isUserWishlist;
@property (nonatomic, strong) NSString *isUserBeenthere;

@property (nonatomic, strong) NSNumber *shouldShowRating;
@property (nonatomic, strong) NSNumber *shouldShowTestimonials;
@property (nonatomic, strong) NSNumber *shouldShowAboutMe;
@property (nonatomic, strong) NSString *aboutMe;
@property (nonatomic, strong) NSString *thisUserRatingStr;
@property (nonatomic, strong) NSString *ratingColor;
@property (nonatomic, strong) NSNumber *numVotes;
@property (nonatomic, strong) NSString *metroNoun;
@property (nonatomic, strong) NSMutableArray *metros;
@property (nonatomic) int showGoogleMaps;
@property (nonatomic) int wineOnly;
@property (nonatomic) int wineAndBeer;
@property (nonatomic) int fullBar;
@property (nonatomic) int byob;
@property (nonatomic) int servesHalaalFood;
@property (nonatomic, strong) NSMutableArray *userUploadedPhotos;
@property (nonatomic, strong) NSString *restThumbURL;
@property (nonatomic, strong) NSNumber *statusId;
@property (nonatomic, strong) NSString *statusText;
@property (nonatomic, strong) NSNumber *photo_count;
@property (nonatomic, strong) NSNumber *zomato_photo_count;
@property (nonatomic, strong) NSNumber *user_photo_count;
@property (nonatomic, strong) NSNumber *insta_photo_count;
@property (nonatomic) int isOpenNow;
@property (nonatomic, strong) NSMutableArray *tips;
@property (nonatomic, strong) NSMutableArray *buffetDetails;
@property (nonatomic, strong) NSMutableArray *brunchDetails;
@property (nonatomic, strong) NSString *template_text;
@property (nonatomic) BOOL isOBP;
@property (nonatomic, strong) NSString *obpURL;
@property (nonatomic, strong) NSNumber *isOpenTableSupported;
@property (nonatomic) BOOL hasMyReview;
@property (nonatomic, strong) NSNumber *partySize;
@property (nonatomic, strong) NSNumber *numOrders;
@property (nonatomic, strong) NSString *bookingTime;
@property (nonatomic, strong) NSNumber *distance;
@property (nonatomic, strong) NSNumber *order_id;
@property (nonatomic, strong) NSNumber *slot_id;
@property (nonatomic, strong) NSNumber *banner_id;
@property (nonatomic, strong) NSNumber *isOpeningSoon;
@property (nonatomic, strong) NSNumber *isTemporarilyClosed;
@property (nonatomic, strong) NSMutableArray *restaurantCollections;
@property (nonatomic, strong) NSNumber *healthRating;
@property (nonatomic, strong) NSString *healthText;
@property (nonatomic, strong) NSString *healthSource;
@property (nonatomic, strong) NSString *reason;
@property (nonatomic, strong) NSNumber *my_review_id;
@property (nonatomic, strong) NSString *typeOfSuggestion;
@property (nonatomic, strong) NSString *meal_Coupon_String;
@property (nonatomic, strong) NSString *highlightDish;
@property (nonatomic, strong) NSString *highlightReview;

@property (weak, nonatomic) id restaurantDelegate;
@property (strong, nonatomic) NSString *groupId;

@property (nonatomic, strong) NSString *knownFor;
@property (nonatomic, strong) NSNumber *checkInCount;
@property (nonatomic, strong) NSNumber *isOnlineDeliveringNow;
@property (nonatomic, strong) NSNumber *hasOnlineDelivery;
@property (nonatomic, strong) RestaurantDeliveryInfo *deliveryInfo;
@property (nonatomic, strong) Promo *deliveryOfferObject;
@property (nonatomic, strong) NSNumber *whitelabelOutletsCount;

//chain links additions
@property (nonatomic, strong) NSString *numOutletsString;
@property (nonatomic, strong) NSNumber *numOutlets;
@property (nonatomic, strong) NSString *entityType;
@property (nonatomic, strong) NSNumber *entityId;
@property (nonatomic,strong) NSNumber *chainId;

//menu message
@property (nonatomic, strong) NSString *menuConsumerUploadedMessage;

//new menus
@property (nonatomic, strong) NSNumber *hasDailyMenu;
@property (nonatomic, strong) NSNumber *hasImageMenu;
@property (nonatomic, strong) NSNumber *hasTextMenu;

@property (nonatomic, strong) NSMutableArray *normalMenus;
@property (nonatomic, strong) NSMutableArray *dailyMenus;
@property (nonatomic, strong) NSString *menuTypesString;

//text menus
@property (nonatomic, strong) NSMutableArray *textMenus;

//distance from landmarks
@property (nonatomic, strong) NSString *distanceFromLandmarks;
@property (nonatomic, strong) NSDictionary *restaurantResponseObject;
@property (nonatomic, strong) NSDictionary *restaurantResponseObjectToBeStoredInDisk;

//mint
@property (nonatomic, strong) NSNumber *openTabSupport;
@property (nonatomic, strong) NSString *openTabMessage;

//expert reviews
@property (nonatomic, strong) NSMutableArray* expertReviews;

//this user checkin count - specific to user only
@property (nonatomic, strong) NSNumber *thisUserCheckinCount;
//Establishment
@property (nonatomic, strong) NSMutableArray *establishments;

//properties to be pre calculated to be shown in search results
@property (nonatomic, strong) NSString *calculatedNearbyDistance;
@property (nonatomic) CGSize writeReviewButtonSize;
@property (nonatomic) CGSize photosButtonSize;
@property (nonatomic) CGSize directionsButtonSize;
@property (nonatomic) CGSize bookTableButtonSize;
@property (nonatomic) CGSize payViaZomatoButtonSize;

@property (nonatomic,strong) NSAttributedString *writeREviewButtonText;
@property (nonatomic,strong) NSAttributedString *addPhotosButtonText;
@property (nonatomic,strong) NSAttributedString *directionsButtonText;
@property (strong, nonatomic) NSMutableAttributedString *photosSearchActionBarString;
@property (strong, nonatomic) NSMutableAttributedString *reviewsSearchActionBarString;
@property (strong, nonatomic) NSMutableAttributedString *directionsSearchActionBarString;

@property (nonatomic, strong) NSNumber *searchCellHeightValue;
@property (strong, nonatomic) NSString *searchParam;
@property (nonatomic) BOOL hasCompleteData;
@property (nonatomic) BOOL isClustered;

@property (nonatomic, strong) NSString *dailyMenuServingStartTime;
@property (nonatomic, strong) NSString *dailyMenuServingEndTime;
@property (nonatomic, strong) NSString *customTimingText;
@property (nonatomic, strong) NSString *ramadanDisclaimer;

//comma separated string of collection ids in which res is featured
@property (nonatomic, strong) NSString *collectionIds;
@property (nonatomic, strong) NSString *displayMenuType;

//properties to be pre calculated to be shown in collection view controller
@property (nonatomic, strong) NSString *distanceFromCityString;

//Attributed Strings to be prebuilt for ZRestaurantSnippetCell
@property (nonatomic, strong) NSAttributedString *infoEstablishmentCuisineAttrString;
@property (nonatomic, strong) NSAttributedString *infoCFTAttrString;
@property (nonatomic, strong) NSAttributedString *infoDistanceFromLandmarkAttrString;
@property (nonatomic, strong) NSAttributedString *infoHighlightReviewAttrString;
@property (nonatomic, strong) NSAttributedString *infoHighlightDishAttrString;
@property (nonatomic, strong) NSAttributedString *infoOffersAttrString;
@property (nonatomic, strong) NSAttributedString *infoEventsAttrString;
@property (nonatomic,strong) NSString *ratingStringFormatted;
@property (nonatomic, strong) NSString *restaurantWebsite;

//has delivery
@property (nonatomic, strong) NSNumber *hasDelivery;

//currency tags
@property (nonatomic, strong) NSString *currencyAffix;
@property (nonatomic, strong) NSString *currency;
@property (nonatomic, strong) NSNumber *has_numeric_cft;


//new from o2
@property (nonatomic, strong) NSString *highlightText;
@property (nonatomic, strong) NSNumber *isDominos;
@property (nonatomic, strong) NSNumber *foodshotsCount;
@property (nonatomic, strong) NSString *o2FeaturedImage;
@property (nonatomic, strong) NSNumber *avgCostForOne;
@property (nonatomic, strong) NSString *openTimingsString;
@property (nonatomic, strong) NSString *closeTimingsString;
@property (nonatomic, strong) NSNumber *hasLoyalty;
@property (nonatomic, strong) NSMutableAttributedString *highlightAttributedString;
@property (nonatomic, strong) NSMutableArray *eventPromosArray;

@property (nonatomic,strong) NSNumber *countryIsdCode;
@property (nonatomic) BOOL isLoadingFullData;

@property (nonatomic) BOOL hasInfoData;
@property (nonatomic) BOOL hasInfoDataFromDisk;

@property (nonatomic, strong) NSMutableArray *idmMenuPicturesArray;

@end
