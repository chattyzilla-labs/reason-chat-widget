open Css;
module Widget = {};
module Launcher = {

  let slide = 
    transitionList([
    Transition.shorthand(
    ~duration=100,
    ~delay=100,
    ~timingFunction=easeInOut,
    "opacity",
   ),
    Transition.shorthand(
    ~duration=100,
    ~delay=100,
    ~timingFunction=easeInOut,
    "transform",
  ),
  ])

  let button =
    style([
      width(px(60)),
      height(px(60)),
      backgroundColor(hex("4e8cff")),
      backgroundPosition(center),
      backgroundRepeat(noRepeat),
      position(fixed),
      right(px(25)), 
      bottom(px(25)), 
      borderRadius(`percent(50.0)), 
      boxShadow(none),
      transition(
        ~duration=200,
        ~delay=200,
        ~timingFunction=easeInOut,
        "boxShadow",
      ),
      hover([
        boxShadow(Shadow.box(~x=zero, ~y=px(0), ~blur=px(27), ~spread=pxFloat(1.5), rgba(0,0,0,0.2)))
      ]),
      before([
        position(relative),
        display(block),
        width(px(60)),
        height(px(60)),
        borderRadius(`percent(50.0)), 
        transition(
        ~duration=200,
        ~delay=200,
        ~timingFunction=easeInOut,
        "boxShadow",
      )
      ])
    ]);

    let buttonOpened = 
    style([
      before([
        boxShadow(Shadow.box(~x=px(0), ~y=px(0), ~blur=px(400), ~spread=px(250), rgba(148, 149, 150, 0.2)))
      ])
    ]);

  let icon = 
    style([
      width(px(60)),
      height(px(60)),
      position(`fixed), 
      right(px(25)), 
      bottom(px(25)), 
      slide
    ]);

      let closeIcon = 
      style([
      padding(px(20)),
      boxSizing(`borderBox),
      opacity(0.0),
      ]);

  let closeIconWhenOpened = style([
    transform(rotate(deg(-90.0))),
    opacity(1.0),
  ]);

  let openIconWhenOpened = style([
    transform(rotate(deg(-90.0))),
    opacity(0.0),
  ]);

  let openIcon = style([
    slide,
    width(px(60)),
    height(px(60)),
  ]);
};



module Badge = {

  let messageCount = style([
    position(absolute),
    top(px(-3)), 
    left(px(41)), 
    display(`flex),
    justifyContent(center), 
    flexDirection(column),
    borderRadius(`percent(100.0)), 
    width(px(22)), 
    height(px(22)),
    background(hex("ff4646")),
    color(white),
    textAlign(center), 
    margin(auto), 
    fontSize(12 |> px),
    fontWeight(`num(500))
  ]);
};
module Conversation = {

  let chatWindow = 
    style([
      width(px(370)),
      height(`calc(`sub, `percent(100.0), px(120))),
      maxHeight(px(590)),
      position(fixed),
      right(px(25)),
      bottom(px(100)),
      boxSizing(borderBox),
      boxShadow(Shadow.box(~x=px(0), ~y=px(7), ~blur=px(40), ~spread=px(0), rgba(148, 149, 150, 0.3))),
      background(white),
      display(`flex),
      flexDirection(column),
      justifyContent(spaceBetween),
      transition(
        ~duration=300,
        ~delay=300,
        ~timingFunction=easeInOut,
        "none"
      ),
      borderRadius(px(10)),
      fontFamily("Helvetica Neue, Helvetica, Arial, sans-serif"),
    ]);
  
};
module Header = {
  let header = style([
    background(hex("4e8cff")),
    minHeight(px(75)),
    borderTopLeftRadius(px(9)),
    borderTopRightRadius(px(9)),
    color(white),
    display(`flex),
    position(`relative),
    boxShadow(Shadow.box(~x=px(0), ~y=px(1), ~blur=px(4), rgba(0, 0, 0, 0.2))),
    padding(px(10)),
    position(`relative),
    boxSizing(`borderBox),
    media("(max-width: 768px)", [
      borderRadius(px(0))
    ])
 
]);

let image = style([
  borderRadius(`percent(50.0)),
  alignSelf(center),
  padding(px(10)),
  width(px(60))
]);

let title = style([
  alignSelf(center),
  padding(px(10)),
  flex(`num(1.0)),
  userSelect(none),
  cursor(`pointer),
  borderRadius(px(5)),
  hover([
    background(hex("4882ed"))
  ])
]);

let closeButton = style([
  width(px(40)),
  alignSelf(center), 
  height(px(40)),
  marginRight(px(10)), 
  boxSizing(`borderBox), 
  cursor(`pointer), 
  borderRadius(px(5)), 
  hover([
    background(hex("4882ed"))
  ])
]);

let closeButtonImage = style([
  width(`percent(100.0)), 
  height(`percent(100.0)), 
  padding(px(13)), 
  boxSizing(`borderBox)
]);



};
module Messages = {

  let messageText = style([
    width(px(300)),
    margin(auto),
    paddingBottom(px(10)),
    display(`flex)

  ])
};
module Loader = {};

module Sender = {

  let userInput = 
    style([
      minHeight(px(55)),
      margin(px(0)),
      position(relative),
      bottom(zero),
      display(`flex),
      backgroundColor(white),
      borderBottomLeftRadius(px(10)),
      borderBottomRightRadius(px(10)),
      transitionList([
        Transition.shorthand(
        ~duration=200,
        ~delay=200,
        ~timingFunction=ease,
        "backgroundColor",
        ),
        Transition.shorthand(
        ~duration=200,
        ~delay=200,
        ~timingFunction=ease,
        "boxShadow",
        ),
      ]),
      active([
        boxShadow(`none),
        backgroundColor(white),

    ])
 ]);

  let userInputText = 
    style([
      width(px(300)),
      resize(none),
      borderStyle(`none),
      outlineStyle(`none),
      borderBottomLeftRadius(px(10)),
      boxSizing(borderBox),
      padding(px(18)),
      fontSize(px(15)),
      fontWeight(`num(400)),
      lineHeight(`abs(1.33)),
      whiteSpace(`preWrap),
      wordWrap(breakWord),
      color(hex("565867")),
      unsafe("-webkit-font-smoothing", "antialiased"),
      maxHeight(px(200)),
      overflow(scroll),
      bottom(zero),
      overflowX(hidden),
      overflowY(auto),
      empty([
        before([
          unsafe("content", "attr(placeholder)"),
          display(block),
          color(rgba(86, 88, 103, 0.3)),
          outlineStyle(`none)
        ])
      ])
    ]);

  let inputButtons = 
    style([
      width(px(100)),
      position(absolute),
      right(px(30)),
      backgroundColor(white),
      height(`percent(100.0)),
      display(`flex),
    ])

  let userInputButton =
    style([
      width(px(30)),
      height(px(55)),
      paddingLeft(px(3)),
      paddingRight(px(3)),
      display(`flex),
      backgroundColor(white),
      flexDirection(column),
      justifyContent(center),
      firstOfType([
        width(px(40)),
        boxShadow(Shadow.box(~x=px(0), ~y=px(-5), ~blur=px(20), ~spread=px(0) , rgba(150, 165, 190, 0.2))),
      ])
    ]);

  let fileContainer = 
    style([
      backgroundColor(hex("f4f7f9")),
      borderTopLeftRadius(px(10)),
      padding2(~v=px(5), ~h=px(20)),
      color(hex("565867"))
    ]);

  let iconFileMessage = 
    style([
      marginRight(px(5)) 
    ]);

  let userInputButtonLabel = 
    style([
      position(relative),
      height(px(24)),
      paddingLeft(px(3)),
      cursor(`pointer)
    ]);

  let deleteFileMessage =
    style([
      fontStyle(normal),
      float(`right),
      cursor(`pointer),
      color(hex("c8cad0")),
      hover([
        color(hex("5d5e6d"))
      ])
    ]);


  

   
};
module Icons = {

  let icon = 
    style([
      height(px(20)),
      width(px(20)),
      cursor(`pointer),
      alignSelf(center),
      SVG.fill(rgba(86, 88, 103, 0.3)),
      outlineStyle(none),
      hover([
        SVG.fill(rgba(86, 88, 103, 1.0))
      ])
    ]);

    let emojiIcon = 
      style([
        height(px(18)),
        cursor(`pointer), 
        SVG.fill(rgba(86, 88, 103, 0.3)),
        alignSelf(center),
        hover([
          SVG.fill(rgba(86, 88, 103, 1.0))
        ])
  ]);


    let iconWrapper = 
    style([
      background(none),
      borderStyle(none), 
      padding(px(0)),
      margin(px(0)),
      outlineStyle(none),
    ]);

    let emojiIconWrapper = 
      style([
        background(none),
        borderStyle(none), 
        padding(px(0)),
        margin(px(0)),
        outlineStyle(none),
        focus([
          outlineStyle(none)
        ])
    ]);

};
