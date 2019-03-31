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
        body: Center(
          child: new CustomCard(),
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
      child: Material(
        elevation: 3.0,
        shadowColor: Colors.red[300],
        borderRadius: new BorderRadius.circular(4.0),
        child: Container(
          height: 200,
          width: double.infinity,
          child: Padding(
            padding: EdgeInsets.all(10.0),
            child: Stack(
              children: [
                // Text(
                //   "50 x 5",
                //   style: TextStyle(
                //     fontWeight: FontWeight.bold,
                //     fontSize: 40,
                //   ),
                // ),
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
                )
              ],
            ),
          ),
        ),
      ),
    );
  }
}
