import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Welcome to Flutter',
      home: Scaffold(
        appBar: AppBar(
          title: Text('Welcome to Flutter'),
        ),
        body: ListView(
          children: [
            new CustomCard(),
            new CustomCard(),
            new CustomCard(),
          ],
        ),
      ),
    );
  }
}

class CustomCard extends StatelessWidget {
  CustomCard({
    Key key,
    // this.argTitle,
    // this.subTitle,
  }) : super(key: key);

  // final String argTitle;
  // final String subTitle;

  @override
  Widget build(BuildContext ctxt) {
    return Padding(
      padding: EdgeInsets.all(10.0),
      child: Container(
        decoration: new BoxDecoration(
          boxShadow: [
            new BoxShadow(
              color: Colors.red[100],
              blurRadius: 15.0,
            ),
          ],
        ),
        child: Material(
          // elevation: 1.0,
          borderRadius: new BorderRadius.circular(4.0),
          child: Container(
            height: 100,
            width: double.infinity,
            child: Padding(
              padding: EdgeInsets.all(10.0),
              child: Column(
                children: [
                  Row(children: [
                    Text(
                      "Warmup set 1",
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                        fontSize: 10,
                      ),
                    ),
                    Expanded(child: SizedBox()),
                    Text(
                      "50 x 5",
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                        fontSize: 30,
                      ),
                    ),
                  ]),
                  SizedBox(
                    // This is a custom divider
                    height: 10.0,
                    child: new Center(
                      child: new Container(
                        margin: new EdgeInsetsDirectional.only(
                            start: 1.0, end: 1.0),
                        height: 2.0,
                        color: Colors.red[100],
                      ),
                    ),
                  ),
                  Row(
                    children: [
                      Text(
                        "5 x ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Image.asset(
                        'assets/2.5.png',
                        width: 17,
                        height: 17,
                        fit: BoxFit.cover,
                      ),
                      Text(
                        " · ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Text(
                        "5 x ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Image.asset(
                        'assets/5.png',
                        width: 17,
                        height: 17,
                        fit: BoxFit.cover,
                      ),
                      Text(
                        " · ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Text(
                        "5 x ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Image.asset(
                        'assets/10.png',
                        width: 17,
                        height: 17,
                        fit: BoxFit.cover,
                      ),
                      Text(
                        " · ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Text(
                        "5 x ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Image.asset(
                        'assets/25.png',
                        width: 17,
                        height: 17,
                        fit: BoxFit.cover,
                      ),
                      Text(
                        " · ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Text(
                        "5 x ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Image.asset(
                        'assets/35.png',
                        width: 17,
                        height: 17,
                        fit: BoxFit.cover,
                      ),
                      Text(
                        " · ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Text(
                        "5 x ",
                        style: TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 17,
                        ),
                      ),
                      Image.asset(
                        'assets/45.png',
                        width: 17,
                        height: 17,
                        fit: BoxFit.cover,
                      ),
                    ],
                  ),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}
