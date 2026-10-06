#!/pxrpythonsubst
#
# Copyright 2020 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.

import sys, unittest
from pxr import Usd, UsdGeom

class TestUsdGeomPoints(unittest.TestCase):

    def test_ComputePointCount(self):
        stage = Usd.Stage.Open('points.usda')
        unset = UsdGeom.Points.Get(stage, '/UnsetPoints')
        blocked = UsdGeom.Points.Get(stage, '/BlockedPoints')
        empty = UsdGeom.Points.Get(stage, '/EmptyPoints')
        timeSampled = UsdGeom.Points.Get(stage, '/TimeSampledPoints')
        timeSampledAndDefault = UsdGeom.Points.Get(
            stage, '/TimeSampledAndDefaultPoints')

        testTimeSamples = [
            (unset, Usd.TimeCode.EarliestTime(), 0),
            (blocked, Usd.TimeCode.EarliestTime(), 0),
            (empty, Usd.TimeCode.EarliestTime(), 0),
            (timeSampled, Usd.TimeCode.EarliestTime(), 3),
            (timeSampledAndDefault, Usd.TimeCode.EarliestTime(), 5)]
        testDefaults = [
            (unset, 0),
            (blocked, 0),
            (empty, 0),
            (timeSampled, 0),
            (timeSampledAndDefault, 4)]

        for (schema, timeCode, expected) in testTimeSamples:
            self.assertTrue(schema)
            self.assertEqual(schema.GetPointCount(timeCode), expected)
        for (schema, expected) in testDefaults:
            self.assertTrue(schema)
            self.assertEqual(schema.GetPointCount(), expected)
 
        invalid = UsdGeom.Points(Usd.Prim())
        self.assertFalse(invalid)
        with self.assertRaises(RuntimeError):
            self.assertEqual(invalid.GetPointCount(), 0)
        with self.assertRaises(RuntimeError):
            self.assertEqual(invalid.GetPointCount(
                Usd.TimeCode.EarliestTime()), 0)

    def test_ComputeExtentFromPluginsWidthsInterpolation(self):
        stage = Usd.Stage.CreateInMemory()
        points = UsdGeom.Points.Define(stage, '/Points')

        def computeExtent():
            return UsdGeom.Boundable.ComputeExtentFromPlugins(
                points, Usd.TimeCode.Default())

        for pointValues in ([(0, 0, 0), (1, 2, 3), (-1, 0, 4)], [(1, 2, 3)]):
            points.GetPointsAttr().Set(pointValues)

            # One width per point.
            points.CreateWidthsAttr([0.1] * len(pointValues))
            points.SetWidthsInterpolation(UsdGeom.Tokens.vertex)
            expected = computeExtent()
            self.assertEqual(len(expected), 2)

            # A single width with constant interpolation applies to all
            # points.
            points.GetWidthsAttr().Set([0.1])
            points.SetWidthsInterpolation(UsdGeom.Tokens.constant)
            self.assertEqual(computeExtent(), expected)

        # A single width that does not match the interpolation is invalid.
        points.GetPointsAttr().Set([(0, 0, 0), (1, 2, 3), (-1, 0, 4)])
        points.SetWidthsInterpolation(UsdGeom.Tokens.vertex)
        self.assertIsNone(computeExtent())

if __name__ == '__main__':
    unittest.main()
