class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        psum = [0]*(n+2)
        for first, last, seats in bookings:
            psum[first] += seats
            psum[last+1] -= seats
        for i in range(1,len(psum)):
            psum[i] += psum[i-1]
        return psum[1:n+1]