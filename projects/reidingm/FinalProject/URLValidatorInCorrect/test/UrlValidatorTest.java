/* Licensed to the Apache Software Foundation (ASF) under one or more
  * contributor license agreements.  See the NOTICE file distributed with
  * this work for additional information regarding copyright ownership.
  * The ASF licenses this file to You under the Apache License, Version 2.0
  * (the "License"); you may not use this file except in compliance with
  * the License.  You may obtain a copy of the License at
  *
  *      http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  */

import junit.framework.TestCase;
import java.util.Random;

/**
  * Performs Validation Test for url validations.
  */
public class UrlValidatorTest extends TestCase {

  public UrlValidatorTest(String testName) {
    super(testName);
  }

  public void testManualTest() {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("\nTesting ALLOW_ALL_SCHEMES Valid Schemes:");
	   System.out.println(urlValidator.isValid("http://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("ftp://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("h3t://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("www.yahoo.com/"));
	   System.out.println("\nTesting ALLOW_ALL_SCHEMES Invalid Schemes:");
	   System.out.println(urlValidator.isValid("http:/www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http:www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http/www.yahoo.com/"));
       System.out.println(urlValidator.isValid("://www.yahoo.com/"));
  }
  
  public void testManualTest1() {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.NO_FRAGMENTS);
	   System.out.println("\nTesting NO_FRAGMENTS Valid Schemes:");
	   System.out.println(urlValidator.isValid("http://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("ftp://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("h3t://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("www.yahoo.com/"));
	   System.out.println("\nTesting ALLOW_ALL_SCHEMES Invalid Schemes:");
	   System.out.println(urlValidator.isValid("http:/www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http:www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http/www.yahoo.com/"));
       System.out.println(urlValidator.isValid("://www.yahoo.com/"));
  }
  
  public void testManualTest2() {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
	   System.out.println("\nTesting ALLOW_LOCAL_URLS Valid Schemes:");
	   System.out.println(urlValidator.isValid("http://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("ftp://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("h3t://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("www.yahoo.com/"));
	   System.out.println("\nTesting ALLOW_ALL_SCHEMES Invalid Schemes:");
	   System.out.println(urlValidator.isValid("http:/www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http:www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http/www.yahoo.com/"));
       System.out.println(urlValidator.isValid("://www.yahoo.com/"));
  }
  
  public void testManualTest3() {
      UrlValidator urlValidator = new UrlValidator(null);
	   System.out.println("\nTesting Default Valid Schemes:");
	   System.out.println(urlValidator.isValid("http://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("ftp://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("h3t://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("www.yahoo.com/"));
	   System.out.println("\nTesting ALLOW_ALL_SCHEMES Invalid Schemes:");
	   System.out.println(urlValidator.isValid("http:/www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http:www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http/www.yahoo.com/"));
       System.out.println(urlValidator.isValid("://www.yahoo.com/"));
  }
  public void testManualTest4() {
      UrlValidator urlValidator = new UrlValidator(null);
	   System.out.println("\nTesting Valid Schemes:");
	   System.out.println(urlValidator.isValidScheme("http://www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("ftp://www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("h3t://www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("www.yahoo.com/"));
	   System.out.println("\nTesting Invalid Schemes:");
	   System.out.println(urlValidator.isValidScheme("http:/www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("http:www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("http/www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("://www.yahoo.com/"));
}
  
  public void testManualTest5() {
	  
      UrlValidator urlValidator = new UrlValidator(goodUrlScheme);
	   System.out.println("\nTesting Valid Authority:");
	   System.out.println(urlValidator.isValidAuthority("www.yahoo.com"));
	   System.out.println(urlValidator.isValidAuthority("go.com"));
	   System.out.println(urlValidator.isValidAuthority("0.0.0.0"));
	   System.out.println(urlValidator.isValidAuthority("255.255.255.255"));
	   System.out.println(urlValidator.isValidAuthority("www.yahoo.com/"));
	   System.out.println(urlValidator.isValidAuthority("www.yahoo.com/"));
	   System.out.println(urlValidator.isValidAuthority("www.yahoo.com/"));
	   System.out.println(urlValidator.isValidAuthority("www.yahoo.com/"));
	   System.out.println("\nTesting Invalid Authority:");
	   System.out.println(urlValidator.isValidAuthority("http://256.256.256.256"));
	   System.out.println(urlValidator.isValidAuthority("http://1.2.3.4.5.6"));
	   System.out.println(urlValidator.isValidAuthority("http://.abc"));
	   System.out.println(urlValidator.isValidAuthority("http://"));
}
  
 public void testManualTest6() {
	  
      UrlValidator urlValidator = new UrlValidator(null);
	   System.out.println("\nTesting Valid Authority:");
       System.out.println(urlValidator.isValidAuthority("http://www.yahoo.com/"));
       System.out.println(urlValidator.isValidAuthority("http://go.com"));
	   System.out.println(urlValidator.isValidAuthority("http://0.0.0.0"));
       System.out.println(urlValidator.isValidAuthority("http://255.255.255.255"));
       System.out.println(urlValidator.isValidAuthority("http://www.yahoo.com/"));
       System.out.println(urlValidator.isValidAuthority("http://www.yahoo.com/"));
       System.out.println(urlValidator.isValidAuthority("h3t://www.yahoo.com"));
       System.out.println(urlValidator.isValidAuthority("www.yahoo.com/"));
	   System.out.println("\nTesting Invalid Authority:");
	   System.out.println(urlValidator.isValidAuthority("http://256.256.256.256"));
	   System.out.println(urlValidator.isValidAuthority("http://1.2.3.4.5.6"));
	   System.out.println(urlValidator.isValidAuthority("http://.abc"));
	   System.out.println(urlValidator.isValidAuthority("http://"));
}
  
  public void testManualTest7() {
      UrlValidator urlValidator = new UrlValidator(goodUrlScheme);
	   System.out.println("\nTesting Valid Schemes:");
	   System.out.println(urlValidator.isValidScheme("http://www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("ftp://www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("h3t://www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("www.yahoo.com/"));
	   System.out.println("\nTesting Invalid Schemes:");
	   System.out.println(urlValidator.isValidScheme("http:/www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("http:www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("http/www.yahoo.com/"));
	   System.out.println(urlValidator.isValidScheme("://www.yahoo.com/"));
}
  
  public void testManualTest8() {
      UrlValidator urlValidator = new UrlValidator(goodUrlScheme);
	   System.out.println("\nTesting Valid Schemes:");
	   System.out.println(urlValidator.isValid("http://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("ftp://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("h3t://www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("www.yahoo.com/"));
	   System.out.println("\nTesting Invalid Schemes:");
	   System.out.println(urlValidator.isValid("http:/www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http:www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("http/www.yahoo.com/"));
	   System.out.println(urlValidator.isValid("://www.yahoo.com/"));
}
  

  // scheme partition
  public void testYourFirstPartition() {
    System.out.println("\nTesting Schemes:\n");
    UrlValidator goodScheme = new UrlValidator(goodUrlScheme, 0);

    for (int i = 0; i < goodUrlScheme.length; i++) {
      System.out.println("\nTesting " + goodUrlScheme[i]);
      if (goodScheme.isValidScheme(goodUrlScheme[i]) == true) 
      {
        System.out.println("Passed\n");
      } 
      
      else 
      {
    	System.out.println("Failed\n");
      }
    }
    
    for (int i = 0; i < badUrlScheme.length - 1; i++) {
        System.out.println("\nTesting " + badUrlScheme[i]);
        if (goodScheme.isValidScheme(badUrlScheme[i]) == false) 
        {
          System.out.println("Passed\n");
        } 
        
        else 
        {
      	System.out.println("Failed\n");
        }
      }
  }

  // authority partition
  public void testYourSecondPartition() {
    System.out.println("\nTesting Authority:\n");
    UrlValidator goodAuthority = new UrlValidator(goodUrlAuthority, 0);

    for (int i = 0; i < goodUrlAuthority.length; i++) {
      System.out.println("\nTesting " + goodUrlAuthority[i]);
      if (goodAuthority.isValidAuthority(goodUrlAuthority[i]) == true) 
      {
        System.out.println("Passed\n");
      } 
      
      else 
      {
    	System.out.println("Failed\n");
      }
    }
    
    for (int i = 0; i < badUrlAuthority.length; i++) {
        System.out.println("\nTesting " + badUrlAuthority[i]);
        if (goodAuthority.isValidAuthority(badUrlAuthority[i]) == false) 
        {
          System.out.println("Passed\n");
        } 
        
        else 
        {
      	System.out.println("Failed\n");
        }
      }
  }

  // port partition - Done with the isValidAuthority(String authority) function
  public void testYourThirdPartition() {
    System.out.println("\nTesting Port:\n");
    UrlValidator goodPort = new UrlValidator(goodUrlPartitionPort, 0);

    for (int i = 0; i < goodUrlAuthority.length; i++) {
      System.out.println("\nTesting " + goodUrlAuthority[i]);
      if (goodPort.isValidAuthority(goodUrlAuthority[i]) == true) 
      {
        System.out.println("Passed\n");
      } 
      
      else 
      {
    	System.out.println("Failed\n");
      }
    }
    
    for (int i = 0; i < badUrlPartitionPort.length - 1; i++) {
        System.out.println("\nTesting " + badUrlPartitionPort[i]);
        if (goodPort.isValidAuthority(badUrlPartitionPort[i]) == false) 
        {
          System.out.println("Passed\n");
        } 
        
        else 
        {
      	System.out.println("Failed\n");
        }
    }
  }

  // path Partition
  public void testYourFourthPartition(){
    System.out.println("\nTesting Path:\n");
    UrlValidator goodPath = new UrlValidator(goodtestPath, 0);

    for (int i = 0; i < goodtestPath.length; i++) {
      System.out.println("\nTesting " + goodtestPath[i]);
      if (goodPath.isValidPath(goodtestPath[i]) == true) 
      {
        System.out.println("Passed\n");
      } 
      
      else 
      {
    	System.out.println("Failed\n");
      }
    }
    
    for (int i = 0; i < badPath.length - 1; i++) {
        System.out.println("\nTesting " + badPath[i]);
        if (goodPath.isValidPath(badPath[i]) == false) 
        {
          System.out.println("Passed\n");
        } 
        
        else 
        {
      	System.out.println("Failed\n");
        }
      }
  }


  // query Partition
  public void testYourFifthPartition() {
    System.out.println("\nTesting Queries:\n");
    UrlValidator goodQuery = new UrlValidator(goodUrlQuery, 0);

    for (int i = 0; i < goodUrlQuery.length; i++) {
      System.out.println("\nTesting " + goodUrlQuery[i]);
      if (goodQuery.isValidQuery(goodUrlQuery[i]) == true) 
      {
        System.out.println("Passed\n");
      } 
      
      else 
      {
    	System.out.println("Failed\n");
      }
    }
  }


  public void testIsValid() {
    int bugCollector = 0;
    Random random=new Random();
    
    System.out.println("\nTesting isValid():\n");
    for(int i = 0; i < 500; i++) {
    	
      // randomize good urls
      String goodURL = goodUrlScheme[random.nextInt(4)] + goodUrlAuthority[random.nextInt(6)] + goodUrlPort[random.nextInt(4)] + goodtestPath[random.nextInt(6)] + goodUrlQuery[random.nextInt(3)];
      UrlValidator goodVal = new UrlValidator();

      // if not valid print url and inrement bugCollector
      if(goodVal.isValid(goodURL) == false) {
    	  System.out.println("\nFailed: \n" + goodURL + "\n");
    	  bugCollector++;
  
      }
      
      // randomize bad urls
      String badURL = badUrlScheme[random.nextInt(5)] + badUrlAuthority[random.nextInt(12)] + badUrlPort[random.nextInt(3)] + badPath[random.nextInt(4)] + goodUrlQuery[random.nextInt(3)];
      // if not valid print url and inrement bugCollector
      if(goodVal.isValid(badURL) == true) {
    	  System.out.println("\nFailed: \n" + goodURL + "\n");
    	  bugCollector++;
      }

    }
    
    // print results
    System.out.println("\nTotal Bugs Collected: " + bugCollector + "\n");
    
  }
  
  
  ResultPair[] testUrls = {new ResultPair("http://www.yahoo.com", true),
          new ResultPair("ftp://www.yahoo.com", true),
          new ResultPair("3ht://www.yahoo.com", false),
          new ResultPair("http:/www.yahoo.com", false)};

// Inputs strings borrowed from URL correct example  
String[] goodUrlScheme = {"http://",
        "ftp://", 
        "h3t://",
        ""};

String[] badUrlScheme = {
        "3ht://",
         "http:/" ,
         "http:" ,
         "http/" ,
         "://" };

String[] goodUrlAuthority = { "www.yahoo.com" ,
            "yahoo.com" ,
            "amazon.ca" ,
            "0.0.0.0" ,
            "255.255.255.255" ,
			"255.com" };

String[]  badUrlAuthority = {
            "256.256.256.256" ,       
            "1.2.3.4.5" ,
            "1.2.3.4." ,
            "1.2.3" ,
            ".1.2.3.4" ,
            "amazon.a" ,
           "weirdend.a1a" ,
            "nope.1aa" ,
            "PreDot." ,
            ".PostDot" ,
            "NoRouting" ,
            "" };


String[] goodUrlPort = { 
	   ":80" ,
       ":65535" ,
       ":0" ,
       ""  };

String[] badUrlPort = {
       ":-1" ,
      ":70000",
       ":60adg" 
      };


String[] goodUrlPartitionPort = { 
	   "www.yahoo.com:80" ,
       "www.yahoo.com:65535" ,
       "www.yahoo.com:0" ,
       "www.yahoo.com"  };

String[] badUrlPartitionPort = {
       "www.yahoo.com:-1" ,
      "www.yahoo.com:70000",
       "www.yahoo.com:65a" 
      };


String[] goodtestPath = { "/yayPath" ,
    "/numberspath123" ,
    "/$23" ,
    "/doubleSlashes/" ,
    "" ,
    "/doublepath/somefile" 
};

String[] badPath = {
    "/..//wonkySlashes" ,
    "/toomandslashes//file", 
"/.." ,
"/../" ,
};

String[] goodUrlQuery = { "?action=view" ,
        "?action=edit&mode=up" ,
        "" 
};
}