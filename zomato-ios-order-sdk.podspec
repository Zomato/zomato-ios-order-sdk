Pod::Spec.new do |s|

  s.name         = "zomato-ios-order-sdk"
  s.version      = "1.4.4"
  s.summary      = "Zomato Order SDK for iOS"

  s.description  = "With Zomato Order SDK for iOS, you can add Online Ordering feature to your application."

  s.homepage     = "https://github.com/Zomato/zomato-ios-order-sdk.git"


  s.license      = { :type => "Copyright", :text =>"Copyright 2016 Zomato Media Private Ltd. All rights reserved."}

  s.author             = "Zomato Media Private Limited"


  s.platform     = :ios

  s.ios.deployment_target = "7.0"

  s.source       = { :git => "https://github.com/Zomato/zomato-ios-order-sdk.git", :tag => "#{s.version}" }


  s.source_files  = "zomato-ios-order-sdk/**/*.{h,m}"



  s.ios.resources = 'Frameworks/*.Bundle'

  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC -lc++' }

  s.vendored_frameworks  = "Frameworks/ZO2Kit.framework"

  s.requires_arc = true


end
