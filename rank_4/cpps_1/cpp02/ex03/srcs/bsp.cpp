#include "../incs/Point.hpp"

// Function to calculate twice the signed area of a triangle
Fixed area(Point const a, Point const b, Point const c) {
    return (a.getX() * (b.getY() - c.getY()) +
            b.getX() * (c.getY() - a.getY()) +
            c.getX() * (a.getY() - b.getY()));
}
// Function to check if a point is inside a triangle
// Calculate twice the signed areas
// Check if the point is inside the triangle or on the boundary
bool bsp(Point const a, Point const b, Point const c, Point const point) {

    Fixed area0 = area(a, b, c);
    Fixed t_area1 = area(point, b, c);
    Fixed t_area2 = area(a, point, c);
    Fixed t_area3 = area(a, b, point);

    bool boundry = ((area0 > 0 && t_area1 >= 0 && t_area2 >= 0 && t_area3 >= 0) ||
                     (area0 < 0 && t_area1 <= 0 && t_area2 <= 0 && t_area3 <= 0) ||
                     (t_area1 == 0 || t_area2 == 0 || t_area3 == 0));

    return boundry;
}


// // The function area calculates twice the signed area of a triangle formed by three 
// points a, b, and c. This value is not the actual area but rather twice the area, 
// which can also be negative depending on the orientation of the points 
// (clockwise or counterclockwise).
// // Why Twice the Area?

// // The formula used in the function:
// // Twice Area=xa(yb−yc)+xb(yc−ya)+xc(ya−yb)
// // Twice Area=xa​(yb​−yc​)+xb​(yc​−ya​)+xc​(ya​−yb​)

// // is derived from the determinant method to calculate the area of a triangle. 
// The formula directly gives twice the area because it avoids the need for 
// division by 2, which simplifies calculations in some algorithms 
// (like checking if a point is inside a triangle).
// // The bsp Function

// // In the bsp (Boundary or Point Inside) function, you're using this 
// "twice the signed area" to check whether a point is inside the triangle or on its 
// boundary:

// //     area0: The twice signed area of the triangle formed by points a, b, and c.
// //     t_area1, t_area2, t_area3: These are the twice signed areas of 
// sub-triangles formed by the point point with two of the triangle's vertices.

// // Checking Point Inside the Triangle

// //     Orientation: The signs of these areas tell you about the 
// orientation. If all areas have the same sign (either all positive or all negative), the point is inside or on the boundary of the triangle.
// //     Boundary Check: The check t_area1 == 0 || t_area2 == 0 || t_area3 == 0 
// helps identify if the point lies exactly on one of the triangle's edges.

// // Summary

// // The function doesn't require dividing by 2 because it's using the twice 
// signed area for simplicity and to avoid fractional calculations. This helps 
// in comparing signs and determining if the point lies inside or on the boundary 
// of the triangle efficiently.