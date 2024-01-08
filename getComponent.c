using System;

class Program
{
    static void Main()
    {
        // Example input values
        double windSpeed = 20;  // Wind speed in knots
        double windDirection = 270;  // Wind direction in degrees (0-360)
        double runwayDirection = 260;  // Runway direction in degrees (0-360)

        // Convert angles to radians
        double windDirectionRad = Math.PI * windDirection / 180;
        double runwayDirectionRad = Math.PI * runwayDirection / 180;

        // Calculate angle difference between wind and runway
        double angleDifference = windDirectionRad - runwayDirectionRad;

        // Adjust the angle to be between -pi and pi
        while (angleDifference > Math.PI)
        {
            angleDifference -= 2 * Math.PI;
        }
        while (angleDifference < -Math.PI)
        {
            angleDifference += 2 * Math.PI;
        }

        // Calculate wind component along runway direction
        double headTailWind = windSpeed * Math.Cos(angleDifference);

        Console.WriteLine($"Head/Tailwind component: {headTailWind:F2} knots");
    }
}
