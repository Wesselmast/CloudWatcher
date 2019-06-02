#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include <QQmlEngine>
#include "generatedshape.h"
#include "globals.h"
#include "math.h"

class BackEnd : public QObject {
    Q_OBJECT
    Q_PROPERTY(double primaryRadius READ get_primary_radius WRITE set_primary_radius)
    Q_PROPERTY(double primarySpikeyness READ get_primary_spikeyness WRITE set_primary_spikeyness)
    Q_PROPERTY(double primaryCurvyness READ get_primary_curvyness WRITE set_primary_curvyness)

    Q_PROPERTY(double secondaryRadius READ get_secondary_radius WRITE set_secondary_radius)
    Q_PROPERTY(double secondarySpikeyness READ get_secondary_spikeyness WRITE set_secondary_spikeyness)
    Q_PROPERTY(double secondaryCurvyness READ get_secondary_curvyness WRITE set_secondary_curvyness)

    Q_PROPERTY(double negativeRadius READ get_negative_radius WRITE set_negative_radius)
    Q_PROPERTY(double negativeSpikeyness READ get_negative_spikeyness WRITE set_negative_spikeyness)
    Q_PROPERTY(double negativeCurvyness READ get_negative_curvyness WRITE set_negative_curvyness)
public:
    static BackEnd& instance() {
        static BackEnd backEnd;
        return backEnd;
    }

    static QObject *create(QQmlEngine *engine, QJSEngine *scriptEngine) {
        Q_UNUSED(engine);
        Q_UNUSED(scriptEngine);

        BackEnd* backEnd = &instance();
        QQmlEngine::setObjectOwnership(backEnd, QQmlEngine::CppOwnership);
        return backEnd;
    }

    inline double get_primary_radius() const { return primaryRadius; }
    inline double get_primary_spikeyness() const { return primarySpikeyness; }
    inline double get_primary_curvyness() const { return primaryCurvyness; }

    inline double get_secondary_radius() const { return secondaryRadius; }
    inline double get_secondary_spikeyness() const { return secondarySpikeyness; }
    inline double get_secondary_curvyness() const { return secondaryCurvyness; }

    inline double get_negative_radius() const { return negativeRadius; }
    inline double get_negative_spikeyness() const { return negativeSpikeyness; }
    inline double get_negative_curvyness() const { return negativeCurvyness; }

    void set_primary_radius(const double& value) {
        primaryRadius = qFloor(map(value, 0, 1, 50, 100));
        generate();
    }
    void set_primary_spikeyness(const double& value) {
        primaryComplexity = qFloor(map(value, 0, 1, 7, 15));
        primarySpikeyness = map(value, 0, 1, 50, 80) * .006;
        generate();
    }
    void set_primary_curvyness(const double& value) {
        primaryCurvyness = qFloor(map(value, 0, 1, 1, 10));
        generate();
    }

    void set_secondary_radius(const double& value) {
        secondaryRadius = qFloor(map(value, 0, 1, 50, 100));
        generate();
    }
    void set_secondary_spikeyness(const double& value) {
        secondaryComplexity = qFloor(map(value, 0, 1, 7, 15));
        secondarySpikeyness = map(value, 0, 1, 50, 80) * .006;
        generate();
    }
    void set_secondary_curvyness(const double& value) {
        secondaryCurvyness = qFloor(map(value, 0, 1, 1, 10));
        generate();
    }

    void set_negative_radius(const double& value) {
        negativeRadius = qFloor(map(value, 0, 1, 30, 70));
        generate();
    }
    void set_negative_spikeyness(const double& value) {
        negativeComplexity = qFloor(map(value, 0, 1, 7, 15));
        negativeSpikeyness = map(value, 0, 1, 50, 80) * .006;
        generate();
    }
    void set_negative_curvyness(const double& value) {
        negativeCurvyness = qFloor(map(value, 0, 1, 1, 10));
        generate();
    }

    Q_INVOKABLE void generate() {
        emit generate_shape();
    }

    Q_INVOKABLE void doExport() {
        emit export_shape();

    }
signals:
    void generate_shape();
    void export_shape();
};

#endif // BACKEND_H
